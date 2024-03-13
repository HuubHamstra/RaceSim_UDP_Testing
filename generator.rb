File.open("input.txt", "r") do |file|
  name = ""
  contents = ""
  variables = []
  file.each_line do |line|
    if line.include?("struct")
      if contents != ""
        contents += "\tunsigned long get(char *buffer)\n\t{\n\t\tunsigned long offset = 0;\n"
        variables.each do |variable|
          contents += "\t\tif (offset < sizeof(buffer))\n\t\t{\n"
          if variable[1].include?("[")
            length = variable[1].split("[")[1].split("]")[0].to_i
            var = variable[1].split("[")[0]
            contents += "\t\t\tfor (int i = 0; i < #{length}; i++)\n\t\t\t{\n\t\t\t\tmemcpy(&this->#{var}[i], &buffer[offset],sizeof(this->#{var}[i]));\n\t\t\t\toffset = offset + sizeof(this->#{var}[i]);\n\t\t\t}\n"
          else
            contents += "\t\t\tmemcpy(&this->#{variable[1]}, &buffer[offset], sizeof(this->#{variable[1]}));\n"
            contents += "\t\t\tthis->#{variable[1]} = static_cast<#{variable[0]}>(this->#{variable[1]});\n" if variable[0].include?("int")
            contents += "\t\t\toffset += sizeof(#{variable[1]});\n"
          end
          contents += "\t\t}\n"
        end
        contents += "\t\treturn offset;\n\t}\n\n\tvoid print()\n\t{\n\t\tstd::cout << \"#{name}:\" << std::endl;\n"
        variables.each do |variable|
          contents += "\t\tstd::cout << \"  #{variable[1]}: \" << this->#{variable[1]} << std::endl;\n"
          if variable[1].include?("[")
            length = variable[1].split("[")[1].split("]")[0].to_i
            var = variable[1].split("[")[0]
            contents += "\t\tfor (int i = 0; i < #{length}; i++)\n\t\t{\n\t\t\t"
            if variable[0].include?("int") || variable[0].include?("float") || variable[0].include?("double") || variable[0].include?("char")
              contents += "std::cout << \"  #{var}[\" << i << \"]: \" << this->#{var}[i] << std::endl;\n"
            else
              contents += "this->#{var}[i].print();\n"
            end
            contents += "\t\t}\n"
          end
        end
        contents += "\t}\n};\n\n#endif"
        File.open(name + ".h", "w") do |file|
          file.puts(contents)
        end
      end
      variables = []
      name = line.split(" ")[1]
      puts "Generating #{name}.h"
      contents = "#ifndef #{name.upcase}_H\n#define #{name.upcase}_H\n\n#include <cstdint>\n#include <iostream>\n\nstruct #{name}\n{\n"
    else
      if line.include?("{") || line.include?("}")
        next
      end
      text = line.gsub("\t", " ").gsub("  ", " ").gsub("  ", " ")
      text_lines = text.split(" ")
      datatype = text_lines[0]
      datatype += "_t" if !datatype.nil? && datatype.include?("int")
      if !["", "//", "struct", "{", "}"].include?(text_lines[0]) && !text_lines[0].nil?
        contents += "\t#{datatype} "
        text_lines.each_with_index do |word, index|
          next if index == 0
          if word.include?(";")
            contents += "#{word}"
          else
            contents += "#{word} "
          end
        end
        contents += "\n"
      else
        contents += "\t#{text}"
      end
      variables.push([datatype, text_lines[1].gsub(";", "")]) if !["", "//", "struct", "{", "}"].include?(text_lines[0]) && !text_lines[0].nil?
    end
  end
end