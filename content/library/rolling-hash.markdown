---
type: algorithm
title: "Rolling-Hash法(Rabin-Karp法)"
tags: [rolling-hash]
comments: true
sharing: true
---

#### 基本情報
  
***

 | 
|:--|:--|
計算量 |
構築 | `$O(N)$`
空間 | `$O(N)$`
  
N := 文字列の長さ  
  

#### 解説

***

文字列からハッシュを生成しておくことでその部分文字列同士の比較をO(1)でできるようにする.  
2つの素数でmodをとるものと2^64でmodをとるものの2つを用意した.  
2^64でmodをとるのは容易にハッシュ衝突を起こす上, そのようなケースを簡単に作れるのでお勧めできない).  
10^9程度の素数でmodをとってもハッシュ衝突をすぐに起こすので複数の素数を使うことにした.  
  
ハッシュの衝突に関しては[ハッシュを衝突させる話](http://hos.ac/blog/#blog0003)が参考になる.


#### コード

***

{{< includeCode "/algorithm/rolling-hash.cpp" "cpp" >}}

#### 問題

***

{% for post in site.tags['rolling-hash'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}

