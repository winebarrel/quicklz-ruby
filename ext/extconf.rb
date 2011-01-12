require 'mkmf'
require 'open-uri'

def download(url)
  dir = File.expand_path(File.dirname(__FILE__))
  dst = File.join(dir, File.basename(url))

  open(url) do |src|
    open(dst, 'w') do |f|
      f << src.read
    end
  end
end

download 'http://www.quicklz.com/quicklz.h'
download 'http://www.quicklz.com/quicklz.c'

create_makefile('qlzruby')
