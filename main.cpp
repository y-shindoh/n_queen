/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	main.cpp
 * @brief	ビット演算を用いたN-queenのサンプル・コマンド
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see https://en.wikipedia.org/wiki/Eight_queens_puzzle
 */

#include <cstdio>
#include <cstdlib>
#include "nqueen.hpp"


int
main(int length,
	 char** arguments)
{
	size_t r, n;

	for (int i(1); i < length; ++i) {
		n = (size_t)std::strtoul(arguments[i], 0, 0);
		r = ys::Nqueen<unsigned int, size_t>::execute(n);
		std::printf("%lu-queen => %lu\n", n, r);
	}

	return 0;
}
