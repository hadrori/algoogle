---
layout: post
title: "Codeforces 430C Xor-tree"
date: 2014-07-04T17:01:00+09:00
comments: true
category: Codeforces
tags: [tree, dfs]
---

[Xor-tree](http://codeforces.com/problemset/problem/430/C)

#### 問題概要

****

頂点数nの根付き木の各頂点は0か1の値をとる.  
ある頂点xを選んで値を反転させたら, その孫, 孫の孫, ...の頂点も反転させる.  
初期状態と目的状態があるとき最小の選択回数と, 選択する頂点を答えよ.

#### 解法

****

根付き木なので根から順に見ていけばそこを反転するかどうかは一意に決まる.  
dfsするときに1つおきの祖先の反転情報を2つもって, 交互に使えばよい.

#### コード

****

{{< includeCode "/Codeforces/430C.cpp" "cpp" >}}
