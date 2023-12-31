/* NetHack may be freely redistributed.  See license for details. */

#ifndef _vulture_gen_h_
#define _vulture_gen_h_

/*--------------------------------------------------------------------------
 General functions
--------------------------------------------------------------------------*/
#include <string>

#include <stdarg.h>

#ifndef __attribute__
#ifndef __GNUC__
#  define __attribute__(x)
#endif
#endif

/* Definitions */
#define V_LOG_ERROR 1
#define V_LOG_NOTE 2
#define V_LOG_DEBUG 3
#define V_LOG_NETHACK 4
#define V_LOG_WRITE_ERROR 1
#define V_LOG_WRITE_NOTE 1
#define V_LOG_WRITE_DEBUG 1

/*
* Subdirectories used by Vulture's.
* These should be under the main directory.
*/
#ifdef _WIN32
# define V_BASE_DIRECTORY     "..\\"
#else
# define V_BASE_DIRECTORY     "../"
#endif

#define V_CONFIG_DIRECTORY   V_BASE_DIRECTORY "config"
#define V_GRAPHICS_DIRECTORY V_BASE_DIRECTORY "graphics"
#define V_SOUND_DIRECTORY    V_BASE_DIRECTORY "sound"
#define V_MUSIC_DIRECTORY    V_BASE_DIRECTORY "music"
#define V_MOVIE_DIRECTORY    V_BASE_DIRECTORY "movie"
#define V_MANUAL_DIRECTORY   V_BASE_DIRECTORY "manual"
#define V_FONTS_DIRECTORY    V_BASE_DIRECTORY "fonts"
#define V_MAP_DIRECTORY      V_BASE_DIRECTORY "map"

#define OOM(do_exit) vulture_oom(do_exit, __FILE__, __LINE__)

extern std::string& trim(std::string &str);
extern char *vulture_basename(char *filename);
extern std::string vulture_make_filename(std::string subdir1, std::string subdir2, std::string name);
extern void vulture_init_gamepath(void);

extern void vulture_write_log(int msgtype, const char *file,
                    int line, const char * logmessage, ...) __attribute__ ((format(printf, 4, 5)));

extern void vulture_write_log_va(int msgtype, const char *file, int line,
                                  const char * logmessage, va_list args);
extern void vulture_oom(int do_exit, const char *file, int line);

extern int vulture_chdir_to_datadir(char * argv0);

extern int vulture_translate_key(int cmd_key);
extern int vulture_numpad_to_hjkl(int cmd_key, int shift);
extern int vulture_make_nh_key(int sym, int mod, int ch);


#endif
