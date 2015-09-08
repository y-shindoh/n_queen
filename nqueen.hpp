/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	nqueen.hpp
 * @brief	ビット演算を用いたN-queenの探索器
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see https://en.wikipedia.org/wiki/Eight_queens_puzzle
 */

#ifndef	__NQUEEN_HPP__
#define	__NQUEEN_HPP__	"nqueen.hpp"

#include <cstddef>
#include <cassert>

namespace ys
{
	/**
	 * ビット演算を用いたN-queenの探索器
	 * @note	テンプレートの型には符号なし整数を適用すること。
	 */
	template<typename DTYPE, typename RTYPE>
	class Nqueen
	{
	private:

		/**
		 * N-queenの探索器 (補助メソッド)
		 * @param[in]	v	クイーンを置けない場所 (水平方向)
		 * @param[in]	l	クイーンを置けない場所 (左斜め上方向)
		 * @param[in]	r	クイーンを置けない場所 (右斜め上方向)
		 * @return	各時点でのパターン (バリエーション解) の総数
		 * @note	引数の「クイーンを置けない場所」は、
					メソッド呼び出し時の状況を表現すれば良い。
		 * @todo	再帰処理を展開して高速化できるか検証する。
		 */
		static RTYPE
		execute(DTYPE v,
				DTYPE l,
				DTYPE r)
			{
				if (v == ~(DTYPE)0) return (RTYPE)1;	// 解を1つ発見

				// クイーンの置けない場所を調整
				l >>= 1;
				r <<= 1;

				DTYPE t = ~(v | l | r);
				DTYPE i;
				RTYPE n(0);

				while (t != 0) {
					i = t ^ (t & (t - (DTYPE)1));	// 置き場所を1つ抽出
					n += Nqueen<DTYPE, RTYPE>::execute(v | i, l | i, r | i);
					t ^= i;
				}

				return n;
			}

	public:

		/**
		 * N-queenの探索器
		 * @param[in]	w	チェス盤の幅・高さ
		 * @return	パターン (バリエーション解) の総数
		 */
		static RTYPE
		execute(DTYPE w)
			{
				assert(w <= sizeof(DTYPE) * 8);

				RTYPE n(0);
				DTYPE v;

				for (DTYPE i(0); i < w / 2; ++i) {
					v = (DTYPE)1 << i;
					n += Nqueen<DTYPE, RTYPE>::execute(v | (~(DTYPE)0 << w), v, v);
				}

				n *= 2;	// 左右対称

				if (w % 2 != 0) {
					v = (DTYPE)1 << (w / 2);
					n += Nqueen<DTYPE, RTYPE>::execute(v | (~(DTYPE)0 << w), v, v);
				}

				return n;
			}
	};
};

#endif	// __NQUEEN_HPP__
