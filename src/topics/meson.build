topics_sources = ['topic1.cpp', 'topic2.cpp']
topics_includes = include_directories('../libbufi')
topics = library('topics', sources: topics_sources,
  include_directories: topics_includes,
  link_with: libbufi,
  install: true
)
