cmake_minimum_required(VERSION 3.10)
project(huffman_RileySuomi)

set(CMAKE_CXX_STANDARD 14)


add_executable(huffman_RileySuomi Main.cpp Letters.cpp Letters.h Table.cpp Table.h Tree.cpp Tree.h TreeNode.cpp TreeNode.h)
