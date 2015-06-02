---
layout: post
title: "PA 2011 Plotter"
date: 2014-11-06T02:25:00+09:00
comments: true
category: PA
tags: [math]
---

[Plotter](http://main.edu.pl/en/archive/pa/2011/plo)

#### 問題概要

****

<div> $ {\displaystyle

L_{1} = L\\
\rightarrow \_L\_ \rightarrow LLR = L_{2}\\
\rightarrow \_L\_L\_R\_ \rightarrow LLRLLRR = L_{3}\\

} $</div>

というように, 次の列は前の列の文字の間にLとRを交互に挿入したもののn個目の列を考える.  
  
原点から初めて(1,1)に線分を伸ばしたものを考える.  
そこからさっきの列を左からみていき, Lなら左に`$sqrt{2}$`進め, Rなら右に`$sqrt{2}$`進める.  
このときm個の座標について, その点を通る回数と通る時刻を列挙せよ

#### 解法

****

列は以下の様な定義に書き換えることができる.

<div> $ {\displaystyle

L_{1} = L\\
L_{i} = L_{i-1}Lr(L_{i})\\

} $</div>

r()は文字列の順序を反転させ, さらにLとRを入れ替えたもの.  
また, `$L_{i}$`が終わった時点での位置は

<div> $ {\displaystyle

x_{i} = x_{i-1}-y_{i-1}\\
y_{i} = x_{i-1}+y_{i-1}\\

} $</div>

nは2000ぐらいだが, クエリで来る座標が`$10^{9}$`程度なので終端点が大幅にはみ出たら適当に打ち切ればいい.  
  
列の新しい定義から, 折れ線の最初と最後の2つに分けて再帰的にみれば線分上にある場合の端点からの距離がわかる.  

<div> $ {\displaystyle

d(x,y,n) = d(x,y,n-1) \cup \{2^{n}-k: k\in d(y_{n}-y,x-x_{n},n-1)\}

} $</div>

しかしこれでは`$O(2^{n})$`で死ぬので枝刈りを入れる.  
得られる折れ線を囲む四角形を考える. その外なら打ち切る.  
原点からの4辺までの距離(原点は四角形の内部であることに注意する)をr, t, l, bとする.

<div> $ {\displaystyle

r_{1} = t_{1} = 1\\
l_{1} = b_{1} = 0\\

r_{i} = max(r_{i-1}, t_{i-1}+x_{i})\\
t_{i} = max(t_{i-1}, l_{i-1}+y_{i})\\
l_{i} = max(l_{i-1}, b_{i-1}-x_{i})\\
b_{i} = max(b_{i-1}, r_{i-1}-y_{i})\\

} $</div>

この枝刈りは根本的で, `$O(n)$`まで削ることができる.

#### コード

****

{{< includeCode "/PA/2011/Plotter.cpp" "cpp" >}}
