Gem::Specification.new do |spec|
  spec.name              = 'qlzruby'
  spec.version           = '0.1.2'
  spec.platform          = 'mswin32'
  spec.summary           = 'Ruby bindings for QuickLZ.'
  spec.require_paths     = %w(lib/i386-mswin32)
  spec.files             = %w(lib/i386-mswin32/qlzruby.so README ext/qlzruby.c LICENSE.txt)
  spec.author            = 'winebarrel'
  spec.email             = 'sgwr_dts@yahoo.co.jp'
  spec.homepage          = 'https://bitbucket.org/winebarrel/quick-ruby'
  spec.has_rdoc          = true
  spec.rdoc_options      << '--title' << 'QuickLZ/Ruby - Ruby bindings for QuickLZ.'
  spec.extra_rdoc_files  = %w(README ext/qlzruby.c LICENSE.txt)
  spec.rubyforge_project = 'qlzruby'
end
