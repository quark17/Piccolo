/*
 * Generated by Bluespec Compiler, version 2017.07.A (build 1da80f1, 2017-07-21)
 * 
 * On Thu Dec 27 20:55:00 EST 2018
 * 
 * To automatically register this VPI wrapper with a Verilog simulator use:
 *     #include "vpi_wrapper_c_trace_file_load_word64_in_buffer.h"
 *     void (*vlog_startup_routines[])() = { c_trace_file_load_word64_in_buffer_vpi_register, 0u };
 * 
 * For a Verilog simulator which requires a .tab file, use the following entry:
 * $imported_c_trace_file_load_word64_in_buffer call=c_trace_file_load_word64_in_buffer_calltf size=32 acc=rw:%TASK
 * 
 * For a Verilog simulator which requires a .sft file, use the following entry:
 * $imported_c_trace_file_load_word64_in_buffer vpiSysFuncSized 32 unsigned
 */
#include <stdlib.h>
#include <vpi_user.h>
#include "bdpi.h"

/* the type of the wrapped function */
unsigned int c_trace_file_load_word64_in_buffer(unsigned int , unsigned long long );

/* VPI wrapper function */
PLI_INT32 c_trace_file_load_word64_in_buffer_calltf(PLI_BYTE8 *user_data)
{
  vpiHandle hCall;
  unsigned int arg_1;
  unsigned long long arg_2;
  unsigned int vpi_result;
  vpiHandle *handle_array;
  
  /* retrieve handle array */
  hCall = vpi_handle(vpiSysTfCall, 0);
  handle_array = vpi_get_userdata(hCall);
  if (handle_array == NULL)
  {
    vpiHandle hArgList;
    hArgList = vpi_iterate(vpiArgument, hCall);
    handle_array = malloc(sizeof(vpiHandle) * 3u);
    handle_array[0u] = hCall;
    handle_array[1u] = vpi_scan(hArgList);
    handle_array[2u] = vpi_scan(hArgList);
    vpi_put_userdata(hCall, handle_array);
    vpi_free_object(hArgList);
  }
  
  /* create return value */
  make_vpi_result(handle_array[0u], &vpi_result, DIRECT);
  
  /* copy in argument values */
  get_vpi_arg(handle_array[1u], &arg_1, DIRECT);
  get_vpi_arg(handle_array[2u], &arg_2, DIRECT);
  
  /* call the imported C function */
  vpi_result = c_trace_file_load_word64_in_buffer(arg_1, arg_2);
  
  /* copy out return value */
  put_vpi_result(handle_array[0u], &vpi_result, DIRECT);
  
  /* free argument storage */
  free_vpi_args();
  vpi_free_object(hCall);
  
  return 0;
}

/* sft: $imported_c_trace_file_load_word64_in_buffer vpiSysFuncSized 32 unsigned */

/* tab: $imported_c_trace_file_load_word64_in_buffer call=c_trace_file_load_word64_in_buffer_calltf size=32 acc=rw:%TASK */

PLI_INT32 c_trace_file_load_word64_in_buffer_sizetf(PLI_BYTE8 *user_data)
{
  return 32u;
}

/* VPI wrapper registration function */
void c_trace_file_load_word64_in_buffer_vpi_register()
{
  s_vpi_systf_data tf_data;
  
  /* Fill in registration data */
  tf_data.type = vpiSysFunc;
  tf_data.sysfunctype = vpiSizedFunc;
  tf_data.tfname = "$imported_c_trace_file_load_word64_in_buffer";
  tf_data.calltf = c_trace_file_load_word64_in_buffer_calltf;
  tf_data.compiletf = 0u;
  tf_data.sizetf = c_trace_file_load_word64_in_buffer_sizetf;
  tf_data.user_data = "$imported_c_trace_file_load_word64_in_buffer";
  
  /* Register the function with VPI */
  vpi_register_systf(&tf_data);
}
