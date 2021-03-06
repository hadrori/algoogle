---
layout: page
title: "赤黒木(marge/split)"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 |
merge | {% m %}O(\log N){% em %}
split | {% m %}O(\log N){% em %}
insert | {% m %}O(\log N){% em %}
erase | {% m %}O(\log N){% em %}
add | {% m %}O(\log N){% em %}
minimum | {% m %}O(\log N){% em %}
空間 | {% m %}O(N){% em %}
  
N := 要素数  
  

#### 解説

***

赤黒木をmerge/splitベースで書いたもの.  
こっちの方がinsert/deleteベースより考えること(場合分け)が少ない.  
赤黒木については[赤黒木(insert/delete)](/algorithm/rbtree.html)を参照のこと  
基本的に葉が各要素に対応している.  
遅延評価を用いることで区間に値を足す操作を{% m %}O(\log N){% em %}程度で行える.  
できること  

* merge: 2つの木のマージ(順番を維持したまま)
* split: 木をk番目で分割(左の木にk個の要素が入る)
* insert: k番目に値valのノードもしくは木vを挿入する
* erase: k番目の葉を削除する
* add: 区間\[l,r)に値valを一様に足す
* minimum: 区間\[l,r)の最小値

#### コード

***

{% include_code algorithm/rbtree_merge.cpp %}

