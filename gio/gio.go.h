#ifndef GO_GIO_H
#define GO_GIO_H

#include <gio/gio.h>

#endif

#include <stdlib.h>

static inline void freeCstr(char* s) { free(s); }
static inline gchar* toGstr(const char* s) { return (gchar*)s; }
static inline char* toCstr(const gchar* s) { return (char*)s; }

static int _check_version(int major, int minor, int micro) {
	return GLIB_CHECK_VERSION(major, minor, micro);
}

#if GLIB_CHECK_VERSION(2, 32, 0)
GBytes* _g_bytes_new_take(gpointer data, gsize size) {
  return g_bytes_new_take(data, size);
}
#else //GLIB_CHECK_VERSION(2, 32, 0)
typedef void GBytes;
GBytes* _g_bytes_new_take(gpointer data, gsize size) {
  return NULL;
}
#endif //GLIB_CHECK_VERSION(2, 32, 0)

#if GLIB_CHECK_VERSION(2, 34, 0)
GInputStream* _g_memory_input_stream_new_from_bytes(GBytes* bytes) {
  return g_memory_input_stream_new_from_bytes(bytes);
}
GIcon* _g_file_info_get_symbolic_icon(GFileInfo* info) {
  return g_file_info_get_symbolic_icon(info);
}
#else //GLIB_CHECK_VERSION(2, 34, 0)
GInputStream* _g_memory_input_stream_new_from_bytes(GBytes* bytes) {
  return NULL;
}
GIcon* _g_file_info_get_symbolic_icon(GFileInfo* info) {
  return NULL;
}
#endif //GLIB_CHECK_VERSION(2, 34, 0)
