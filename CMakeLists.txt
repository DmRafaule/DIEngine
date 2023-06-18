cmake_minimum_required(VERSION 3.5)
project(DIEngine VERSION 0.1 DESCRIPTION "Core of DI engine" LANGUAGES CXX)

file( GLOB SOURCES **.cpp )

SetFlags()
SetLibraries( DIGUI )
CreateLibrary( ${PROJECT_NAME} )