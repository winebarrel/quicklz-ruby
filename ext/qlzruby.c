#ifdef _WIN32
__declspec(dllexport) void Init_qlzruby(void);
#include <malloc.h>
#else
#include <alloca.h>
#endif

#include <string.h>
#include "quicklz.h"
#include "ruby.h"

#ifndef RSTRING_PTR
#define RSTRING_PTR(s) (RSTRING(s)->ptr)
#endif

#ifndef RSTRING_LEN
#define RSTRING_LEN(s) (RSTRING(s)->len)
#endif

#define Check_IO(x) do { \
  const char *classname = rb_class2name(CLASS_OF(x)); \
  if (rb_obj_is_instance_of((x), rb_cIO)) { \
    rb_io_binmode(x); \
  } else if (strcmp(classname, "StringIO") != 0) { \
    rb_raise(rb_eTypeError, "wrong argument type %s (expected IO or StringIO)", classname); \
  } \
} while(0)

#define VERSION "0.1.2"
#define DEFAULT_BLOCKSIZE 5120
#define HEADER_LEN 9

/* */
static VALUE qlzruby_compress(VALUE self, VALUE v_src) {
  VALUE v_dst;
  char *src, *dst;
  qlz_state_compress *state_compress;
  size_t len;

  Check_Type(v_src, T_STRING);
  src = RSTRING_PTR(v_src);
  len = RSTRING_LEN(v_src);
  state_compress = (qlz_state_compress *) xmalloc(sizeof(qlz_state_compress));
  dst = xmalloc(len + 400);
  len = qlz_compress(src, dst, len, state_compress);
  v_dst = rb_str_new(dst, len);
  xfree(state_compress);
  xfree(dst);

  return v_dst;
}

/* */
static VALUE qlzruby_decompress(VALUE self, VALUE v_src) {
  VALUE v_dst;
  char *src, *dst;
  qlz_state_decompress *state_decompress;
  size_t len;

  Check_Type(v_src, T_STRING);
  src = RSTRING_PTR(v_src);
  len = qlz_size_decompressed(src);
  dst = xmalloc(len);
  state_decompress = (qlz_state_decompress *) xmalloc(sizeof(qlz_state_decompress));
  len = qlz_decompress(src, dst, state_decompress);
  v_dst = rb_str_new(dst, len);
  xfree(state_decompress);
  xfree(dst);

  return v_dst;
}

void Init_qlzruby() {
  VALUE QuickLZ = rb_define_module("QuickLZ");
  rb_define_const(QuickLZ, "VERSION", rb_str_new2(VERSION));
  rb_define_module_function(QuickLZ, "compress", qlzruby_compress, 1);
  rb_define_module_function(QuickLZ, "decompress", qlzruby_decompress, 1);
}
