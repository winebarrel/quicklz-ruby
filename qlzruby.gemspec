Gem::Specification.new do |spec|
  spec.name              = 'qlzruby'
  spec.version           = '0.1.2'
  spec.summary           = 'Ruby bindings for QuickLZ.'
  spec.files             = Dir.glob('ext/**/*.{c,h}') + %w(ext/extconf.rb README LICENSE.txt)
  spec.author            = 'winebarrel'
  spec.email             = 'sgwr_dts@yahoo.co.jp'
  spec.homepage          = 'https://bitbucket.org/winebarrel/quick-ruby'
  spec.extensions        = 'ext/extconf.rb'
  spec.has_rdoc          = true
  spec.rdoc_options      << '--title' << 'QuickLZ/Ruby - Ruby bindings for QuickLZ.'
  spec.extra_rdoc_files  = %w(README ext/qlzruby.c LICENSE.txt)
end
