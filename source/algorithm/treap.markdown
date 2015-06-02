---
layout: page
title: "Treap"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 |
insert | {% m %}O(\log N){% em %}
erase | {% m %}O(\log N){% em %}
merge | {% m %}O(\log N){% em %}
split | {% m %}O(\log N){% em %}
空間 | {% m %}O(N){% em %}
  
N := 要素数  
  

#### 解説

***

insert: 位置kに値valを挿入  
erase: 位置kのノードを削除  
merge: 木sと木tをマージ  
split: 位置kで木を2つに分ける  
  
Treapは二分探索木とヒープの両方の特徴を持っている.  
ノードに優先度をつけ優先度が高い方が親にくる.  
優先度をランダムに決めることでおおむね平衡になる.  
実装が赤黒木などと比較して楽.  
詳しくは[プログラミングコンテストでのデータ構造 2　～平衡二分探索木編～](http://www.slideshare.net/iwiwi/2-12188757)を参照のこと


#### コード

***

{% include_code algorithm/treap.cpp %}

