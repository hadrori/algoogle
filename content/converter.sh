#!/bin/sh
find . -type f -exec sed -i "" -e 's/<pre><code class="cpp">{{% include_code "code\(.*\)" %}}<\/code><\/pre>/{{< includeCode "\1" "cpp" >}}/g' {} \;
find . -type f -exec sed -i "" -e 's/\[download\](\(.*\))//g' {} \;
find . -type f -exec sed -i "" -e 's/<pre><code class="haskell">{{% include_code "code\(.*\)" %}}<\/code><\/pre>/{{< includeCode "\1" "haskell" >}}/g' {} \;
find . -type f -exec sed -i "" -e 's/{% include_code \(.*\).d %}/{{< includeCode "\/\1.d" "d" >}}/g' {} \;
find . -type f -exec sed -i "" -e 's/{{< includeCode "\(.*\)" "d" >}}/{{< includeCode "\1.d.d" "d" >}}/g' {} \;
