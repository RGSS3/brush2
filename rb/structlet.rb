module StructLet
  MAP = {
    "int" => "%d",
    "float" => "%f",
    "double" => "%lf",
  }
  def self.typeof(type)
     if type[/char\s*\[/]
       ["%s", ""]
     else
       [MAP[type], "&"]
     end
  end
  def self.readin(name, type)
    a, p = typeof(type)
    %{scanf("#{a}", #{p}#{name});\n}
  end
  def self.writeout(name, type)
    %{printf("#{typeof(type)[0]},", #{name});\n}
  end
end
def structlet(name, aa, args = {})
    args = aa.map{|x| [x, "int"]} + args.to_a
    %{struct #{name} {
#{args.map{|k, v| " __typeof(#{v}) #{k};\n"}.join}
  void read() {
#{args.map{|k, v| "    " + StructLet.readin(k, v)}.join}   
  }
  void print() {
#{args.map{|k, v| "    " + StructLet.writeout(k, v)}.join} 
    puts("");
  }
};}
end
