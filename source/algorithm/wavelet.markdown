---
layout: page
title: "Wavelet-Matrix"
published: false
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 |
完備辞書 | 
rank | {% m %}O(1){% em %}
select | {% m %}O(\log N){% em %}
Wavelet行列 |
rank | {% m %}O(\log M){% em %}
select | {% m %}O(\log M \log \log M){% em %}
access | {% m %}O(1){% em %}
quantile | {% m %}O(\log M){% em %}
maximum | {% m %}O(\log M){% em %}
minimum | {% m %}O(\log M){% em %}
topk | {% m %}O(\log^{3} M){% em %}
range_maxk | {% m %}O(\log M){% em %}
range_freq | {% m %}O(K\log M){% em %}
range_list | {% m %}O(K\log M){% em %}
range_rect | {% m %}O(K\log M){% em %}
range_exist | {% m %}O(\log M){% em %}
空間 | {% m %}O(N\log M){% em %}
  
N := 元の列の長さ  
M := 最大値  
K := その操作によって得られる列の長さ(<=r-l)  



#### 解説

***

静的なデータ構造.  
特に2次元に関するクエリに強い.  
計算量はかなり適当なのでもっと削れるかも.  
完備辞書のselectが{% m %}\log N{% em %}かかっているのでselectを多用すると遅い.  
またvectorでとっているのでそこもボトルネックになる. 必要なら配列で書き直したほうがよい.  
現在はめちゃくちゃ長いが行き当たりばったりの実装なのでいずれ整理してもっと短くしたい.  
詳しい解説は[ウェーブレット木の世界](http://www.slideshare.net/pfi/ss-15916040)  
  
完備辞書  
popcountはgcc拡張のやつが爆速なのでそれを使う.  
そうでない場合は適当にビット操作頑張ってやればいいでしょう.  
selectの内部は二分探索を展開してるだけなので実際には{% m %}O(\log^{2} N){% em %}になる.  

* rank: 区間\[0,r)にあるvalの個数
* select: i番目のvalの位置
* \[\]: i番目の要素

Wavelet行列

* rank: 区間\[0,r)にあるvalの個数
* select: i番目のvalの位置
* access, \[\]: i番目の要素
* quantile: 区間\[l,r)でi番目に大きい数
* topk: 区間\[l,r)で出現回数が多い順にk個
* range_maxk: 区間\[l,r)で大きい順にk個
* range_freq: 区間\[l,r)で値が\[lb,ub)になる要素の数
* range_list: 区間\[l,r)で値が\[lb,ub)になる値とその出現回数の組のリスト
* range_rect: 区間\[l,r)で値が\[lb,ub)になる要素の位置とその値の組(つまり矩形内にある点の座標)のリスト
* range_exist: 区間\[l,r)で値が\[lb,ub)になる要素が存在するか

完備辞書とwaveletのrank, select, range_freq, range_existのみverified.
  
#### コード

***

{% include_code algorithm/wavelet.cpp %}

