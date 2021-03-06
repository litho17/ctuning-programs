/* 
 Codelet from MILEPOST project: http://cTuning.org/project-milepost
 Updated by Grigori Fursin to work with Collective Mind Framework

 3 "./tiffmedian.codelet__5.wrapper.c" 3 4
*/

#include <stdio.h>

int __astex_write_message(const char * format, ...);
int __astex_write_output(const char * format, ...);
void __astex_exit_on_error(const char * msg, int code, const char * additional_msg);
void * __astex_fopen(const char * name, const char * mode);
void * __astex_memalloc(long bytes);
void __astex_close_file(void * file);
void __astex_read_from_file(void * dest, long bytes, void * file);
int __astex_getenv_int(const char * var);
void * __astex_start_measure();
double __astex_stop_measure(void * _before);
typedef unsigned short  uint16;
typedef uint16  tdir_t;
typedef uint16  tsample_t;
typedef struct   {
  int  num_ents;
  int  entries[256][2];
} C_cell;
void  astex_codelet__5(uint16 rm[256], uint16 gm[256], uint16 bm[256], int *histp, C_cell *cell, int dist, int ir, int ig, int ib);
int main(int argc, const char **argv)
{
  uint16  *rm;
  uint16  *gm;
  uint16  *bm;
  int  *histp;
  C_cell  *cell;
  int  dist = 9999999;
  int  ir = 0;
  int  ig = 0;
  int  ib = 0;
  void * codelet_data_file_descriptor = (void *) 0;

#ifdef OPENME
  openme_init(NULL,NULL,NULL,0);
  openme_callback("PROGRAM_START", NULL);
#endif

  if (argc < 2)
    __astex_exit_on_error("Please specify data file in command-line.", 1, argv[0]);
  codelet_data_file_descriptor = __astex_fopen(argv[1], "rb");
  
  char * rm__region_buffer = (char *) __astex_memalloc(512);
  __astex_write_message("Reading rm value from %s\n", argv[1]);
  __astex_read_from_file(rm__region_buffer, 512, codelet_data_file_descriptor);
  rm = (uint16 *) (rm__region_buffer + 0l);
  char * gm__region_buffer = (char *) __astex_memalloc(512);
  __astex_write_message("Reading gm value from %s\n", argv[1]);
  __astex_read_from_file(gm__region_buffer, 512, codelet_data_file_descriptor);
  gm = (uint16 *) (gm__region_buffer + 0l);
  char * bm__region_buffer = (char *) __astex_memalloc(512);
  __astex_write_message("Reading bm value from %s\n", argv[1]);
  __astex_read_from_file(bm__region_buffer, 512, codelet_data_file_descriptor);
  bm = (uint16 *) (bm__region_buffer + 0l);
  char * histp__region_buffer = (char *) __astex_memalloc(131072);
  __astex_write_message("Reading histp value from %s\n", argv[1]);
  __astex_read_from_file(histp__region_buffer, 131072, codelet_data_file_descriptor);
  histp = (int *) (histp__region_buffer + 0l);
  char * cell__region_buffer = (char *) __astex_memalloc(2052);
  __astex_write_message("Reading cell value from %s\n", argv[1]);
  __astex_read_from_file(cell__region_buffer, 2052, codelet_data_file_descriptor);
  cell = (C_cell *) (cell__region_buffer + 0l);
  void * _astex_timeval_before = __astex_start_measure();
  int _astex_wrap_loop = __astex_getenv_int("CT_REPEAT_MAIN");
  if (! _astex_wrap_loop)
    _astex_wrap_loop = 1;

#ifdef OPENME
  openme_callback("KERNEL_START", NULL);
#endif

  while (_astex_wrap_loop > 0)
  {
    --_astex_wrap_loop;
  astex_codelet__5(rm, gm, bm, histp, cell, dist, ir, ig, ib);

  }

#ifdef OPENME
  openme_callback("KERNEL_END", NULL);
#endif

  __astex_write_output("Total time: %lf\n", __astex_stop_measure(_astex_timeval_before));


#ifdef OPENME
  openme_callback("PROGRAM_END", NULL);
#endif

  return 0;
}

