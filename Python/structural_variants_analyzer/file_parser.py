import pandas as pd
import numpy as np

class VCFParser:
   
   def __init__ (self, file):
        self.file = file
        self.info_map = {}
         
   def info_string_to_dict(self, chromosome, position, info_str):
       # Map create a key using the chromosome and position.
       key = (chromosome, position)

       info_list = info_str.strip().split(';')
       # Create a nested dictionary to create callable information later.
       inner_dict = {}
       for info in info_list:
           if '=' in info:
            k , v = info.split('=')
           inner_dict[k] = v
        
       self.info_map[key] = inner_dict

   def clean_data(self):
       
       matrix = []
       with open(self.file, 'r') as data_file:
            for line in data_file:

                if line.startswith('##'):
                    continue
                if line.startswith('#'):
                    column_names = line.strip().split('\t')
                    column_names = column_names[:8]
                    matrix.append(column_names)
                    continue

                column = line.strip().split('\t')
                self.info_string_to_dict(column[0], column[1], column[7])
                matrix.append(column[:8])
            
            return np.array(matrix)
                

if __name__ == '__main__':

    file_parsed = VCFParser('ALL.wgs.mergedSV.v8.20130502.svs.genotypes.vcf')
    data = file_parsed.clean_data()
    print(file_parsed.info_map['1','645710']['AC'])
