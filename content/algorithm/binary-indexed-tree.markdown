---
type: page
title: "Binary Indexed Tree"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 | `$O(\log N)$`
用途 | 区間の和を求める. 値を加える.
  
N := 区間の幅  
  
#### 解説

***
BIT(Binary Indexed Tree)は区間の和を求めるのと1つの場所の値に加算するのををO(log N)で行えるデータ構造. 
実現にビットを用いていて実装が非常に楽.  
値の加算はi番目の値に加えたい場合は立っているビットの最後のビットを繰り上げていきながらその経路全てを更新する.  
和の計算は0からi-1番目までの値の和の場合, 立っているビットの最後のbitを0にしながらその経路全ての和を返す.  

#### コード

***

{{< includeCode "/algorithm/bit.cpp" "cpp" >}}

#### 参考

***

* [http://hos.ac/slides/20140319_bit.pdf](http://hos.ac/slides/20140319_bit.pdf)


#### 問題

***  
{% for post in site.tags['binary-indexed-tree'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}
