import pandas as pd
import numpy as np

class VCFParser:
   
   def __init__ (self, file):
        self.file = file
        self.info_map = {}
         
   def info_string_to_dict(self, chromosome, position, info_str):
       key = (chromosome, position)
       self.info_map[key] = info_str


       

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

                column = line.strip().split('\t')
                self.info_string_to_dict(column[0], column[1], column[7])
                matrix.append(column[:8])
            return np.array(matrix)
                





if __name__ == '__main__':

    file_parsed = VCFParser('ALL.wgs.mergedSV.v8.20130502.svs.genotypes.vcf')
    data = file_parsed.clean_data()
    print(file_parsed.info_map['1','645710'])
