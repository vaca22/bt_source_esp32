#ifndef _FATFS_STREAM_H_
#define _FATFS_STREAM_H_

#include "audio_error.h"
#include "audio_element.h"
#include "audio_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   FATFS Stream configurations, if any entry is zero then the configuration will be set to default values
 */
typedef struct {
    audio_stream_type_t     type;           /*!< Stream type */
    int                     buf_sz;         /*!< Audio Element Buffer size */
    int                     out_rb_size;    /*!< Size of output ringbuffer */
    int                     task_stack;     /*!< Task stack size */
    int                     task_core;      /*!< Task running in core (0 or 1) */
    int                     task_prio;      /*!< Task priority (based on freeRTOS priority) */
    bool                    ext_stack;      /*!< Allocate stack on extern ram */
    bool                    write_header;   /*!< Choose to write amrnb/amrwb header in fatfs whether or not (true or false, true means choose to write amrnb header) */
} tf_stream_cfg_t;


#define FATFS_STREAM_BUF_SIZE            (2048)
#define FATFS_STREAM_TASK_STACK          (3072)
#define FATFS_STREAM_TASK_CORE           (0)
#define FATFS_STREAM_TASK_PRIO           (4)
#define FATFS_STREAM_RINGBUFFER_SIZE     (8 * 1024)

#define TF_STREAM_CFG_DEFAULT() {             \
    .type = AUDIO_STREAM_NONE,                   \
    .buf_sz = FATFS_STREAM_BUF_SIZE,             \
    .out_rb_size = FATFS_STREAM_RINGBUFFER_SIZE, \
    .task_stack = FATFS_STREAM_TASK_STACK,       \
    .task_core = FATFS_STREAM_TASK_CORE,         \
    .task_prio = FATFS_STREAM_TASK_PRIO,         \
    .ext_stack = false,                          \
    .write_header = true,                        \
}

/**
 * @brief      Create a handle to an Audio Element to stream data from FatFs to another Element
 *             or get data from other elements written to FatFs, depending on the configuration
 *             the stream type, either AUDIO_STREAM_READER or AUDIO_STREAM_WRITER.
 *
 * @param      config  The configuration
 *
 * @return     The Audio Element handle
 */
audio_element_handle_t tf_stream_init(tf_stream_cfg_t *config);

#ifdef __cplusplus
}
#endif

#endif
