#pragma once
#include <unordered_map>
#include <string>

std::unordered_map<char, float> KTNormalizedAminoScores 
{
    //Generated from tcl normalized dictionary
    {'A', 0.7f},     // ALA
    {'R', 0.0f},     // ARG
    {'N', 0.111f},   // ASN
    {'D', 0.111f},   // ASP
    {'C', 0.778f},   // CYS
    {'Q', 0.111f},   // GLN
    {'E', 0.111f},   // GLU
    {'G', 0.456f},   // GLY
    {'H', 0.144f},   // HIS
    {'I', 1.0f},     // ILE
    {'L', 0.922f},   // LEU
    {'K', 0.067f},   // LYS
    {'M', 0.711f},   // MET
    {'F', 0.811f},   // PHE
    {'P', 0.322f},   // PRO
    {'S', 0.411f},   // SER
    {'T', 0.422f},   // THR
    {'W', 0.4f},     // TRP
    {'Y', 0.356f},   // TYR
    {'V', 0.967f},   // VAL
    {'U', 0.5f}      // SEC (selenocysteine)

};
