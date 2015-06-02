---
layout: page
title: "線形方程式の解(Givens)"
comments: true
sharing: true
---

#### 基本情報
  
***


#### 解説

***

Givens回転を用いたQR分解によって線形方程式を解く.  
参考資料 : [競技プログラミングでの線型方程式系](http://www.slideshare.net/tmaehara/ss-18244588)  
スライドのコードはミスがあった気がするので注意.

#### コード

***

{% include_code algorithm/givens.cpp %}

#### 問題

***

{% for post in site.tags['givens'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}
