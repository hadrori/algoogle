---
layout: page
title: "Binary Indexed Tree(Range Add)"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 | {% m %}O(\log N){% em %}
用途 | 区間の和を求める. 区間に値を加える.
  
N := 区間の幅  
  
#### 解説

***

[BIT](/algorithm/binary-indexed-tree.html)で区間に値を足すバージョン.  
BITでやらなくてもSegment Treeでやればいいですが, BITを使って少し工夫するだけでいいので知っておくと便利です.  
  
解説は[Binary Indexed Treeのはなし](http://hos.ac/slides/20140319_bit.pdf)の57ページ目あたりから読むとわかりやすいです.

#### コード

***

{% include_code algorithm/bitr.cpp %}

#### 参考

***

* [http://hos.ac/slides/20140319_bit.pdf](http://hos.ac/slides/20140319_bit.pdf)


#### 問題

***  
{% for post in site.tags['binary-indexed-tree-range'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}