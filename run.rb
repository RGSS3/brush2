require 'yaml'
require 'erb'
x = File.read(ARGV[0])
y = YAML.load File.read("snippet.yml")


def eval_node_condition(n, env)
    return true if n["condition"] && eval(n["condition"]) 
    return true if n["match"] && env[:text] =~ Regexp.new(n["match"])
    false
end

def eval_node(n, env)
    if n["file"]
        File.read n["file"]
    elsif n["code"]
        n["code"]
    elsif n["eval"]
        eval(n["eval"])
    end
end
if FileTest.exists?(ARGV[1]) && File.mtime(ARGV[1]) >= File.mtime(ARGV[0])
    puts "Up-to-date"
    exit
end

env = {:text => x}
add = []
y.each{|c|
    if eval_node_condition(c, env)
        puts "Adding #{c["name"]}"
        add << eval_node(c, env)
    end
}
File.write "tmp1", add.join("\n") + "\n" + x
system "cpp tmp1 > tmp2"
text = File.read "tmp2"
text.gsub!(/^# \d+ .*$/, "")
Dir.glob("./rb/*.rb", &method(:require))
s = ERB.new(text).result(binding)
File.write ARGV[1], %{#include <bits/stdc++.h>
using namespace std;
#{s}
}



