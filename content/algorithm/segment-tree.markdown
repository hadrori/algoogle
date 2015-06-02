---
type: page
title: "Segment Tree"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量(RMQ) | `$O(\log N)$`
用途 | 区間に対するクエリの処理
  
N := 区間の幅  

#### 解説

***

Segment Treeは主に区間に対するクエリを処理するために使われる.  
完全二分木で実装されるので各クエリの計算量はO(log N)になる.  
自由度が高く, 区間を扱う様々なものに利用される.  
コードはRMQとその区間足し込みバージョンの実装.  
この2つの書き方をなんとなくイメージできればある程度柔軟に実装できるようになるでしょう.  
区間足し込みはその区間全体に一気に足された数というのを遅延評価することで`$O(\log N)$`実現できる.

#### コード

***

{{< includeCode "/algorithm/segtree.cpp" "cpp" >}}

{{< includeCode "/algorithm/segtree2.cpp" "cpp" >}}


#### 問題

***  
{% for post in site.tags['segment-tree'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}
