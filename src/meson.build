subdir('libbufi')
subdir('topics')

bufi_includes = include_directories('topics')

executable('bufi', 'main.cpp',
  include_directories: bufi_includes,
  link_with: topics,
  install: true
)
