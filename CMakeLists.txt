cmake_minimum_required(VERSION 3.21)
project(untitled1)

set(CMAKE_CXX_STANDARD 11)

#progetto usando memoria dinamica standard
add_executable(untitled1 main.cpp Stanza.cpp Stanza.h Pavimento.cpp Pavimento.h Palazzo.cpp Palazzo.h)

#progetto usando la classe vector, quindi con utilizzo di vettori di alto livello; risulta più semplice la gestione di aggiunta stanze e la gestione della memoria
# add_executable(untitled1 main2.cpp Stanza.cpp Stanza.h Pavimento.cpp Pavimento.h Palazzo2.cpp Palazzo2.h)
