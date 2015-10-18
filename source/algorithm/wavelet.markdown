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
get | {% m %}O(1){% em %}
maximum | {% m %}O(\log M){% em %}
kth_number | {% m %}O(\log M){% em %}
freq | {% m %}O(\log M){% em %}
freq_list | {% m %}O(K\log M){% em %}
get_rect | {% m %}O(K\log M){% em %}
空間 | {% m %}O(N){% em %}
  
N := 元の列の長さ  
M := 最大値  
K := その操作によって得られる列の長さ(<=r-l)  



#### 解説

***

静的なデータ構造.  
特に2次元に関するクエリに強い.  
計算量はかなり適当なのでもっと削れるかも.  
完備辞書のselectが{% m %}\log N{% em %}かかっているのでselectを多用すると遅い.  
selectをO(1)にする方法について:[http://algo2.iti.kit.edu/download/ads_lec11.pdf](http://algo2.iti.kit.edu/download/ads_lec11.pdf)  

現在はめちゃくちゃ長いが行き当たりばったりの実装なのでいずれ整理してもっと短くしたい.  
詳しい解説は[ウェーブレット木の世界](http://www.slideshare.net/pfi/ss-15916040)  
  
popcountはstaticにとって1回だけ計算する．  

* rank: 区間\[0,r)にあるvalの個数
* select: i番目のvalの位置
* \[\]: i番目の要素

Wavelet行列

* rank: 区間\[0,r)にあるvalの個数
* select: i番目のvalの位置
* get, \[\]: i番目の要素
* kth_number: 区間\[l,r)でk番目に大きい数
* maximum: 区間\[l,r)で大きい順にk個
* freq: 区間\[l,r)で値が\[lb,ub)になる要素の数
* freq_list: 区間\[l,r)で値が\[lb,ub)になる値とその出現回数の組のリスト
* get_rect: 区間\[l,r)で値が\[lb,ub)になる要素の位置とその値の組(つまり矩形内にある点の座標)のリスト

maximum以外はverified．

#### コード

***

{% include_code algorithm/wavelet.cpp %}

