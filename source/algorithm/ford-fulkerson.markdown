---
layout: page
title: "Ford-Fulkerson法"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 | {% m %}O(FE){% em %}
用途| 最大流を求める
  
F := 最大流の流量
E := 辺の数


#### 解説

***

始点から終点までにフローを流せるパスが存在する限りそこに流し続ける.  
パスに使った辺の容量は減らし, 逆辺の容量を増やす.  
非常に単純.  
欠点として容量が無理数である場合, 有限回の操作で終了しないことが知られているが, 競技プログラミングにおいてはそのようなケースは稀.  

また最大流を利用することで, 2部グラフの最大マッチング問題を解くことができる. ソース->集合A->集合B->シンク と容量1の辺を張ることで最大流が最大マッチングに対応する.

#### コード

***

{% include_code algorithm/ford_fulkerson.cpp %}



#### 問題

***  

{% for post in site.tags['max-flow'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}