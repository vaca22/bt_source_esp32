/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2018 <ESPRESSIF SYSTEMS (SHANGHAI) PTE LTD>
 *
 * Permission is hereby granted for use on all ESPRESSIF SYSTEMS products, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __CJC8988_H__
#define __CJC8988_H__

#include "esp_types.h"
#include "audio_hal.h"
#include "driver/i2c.h"
#include "esxxx_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* CJC8988 address */
#define CJC8988_ADDR 0x20  /*!< 0x22:CE=1;0x20:CE=0*/

/* CJC8988 register */
#define CJC8988_CONTROL1         0x00
#define CJC8988_CONTROL2         0x01

#define CJC8988_CHIPPOWER        0x02

#define CJC8988_ADCPOWER         0x03
#define CJC8988_DACPOWER         0x04

#define CJC8988_CHIPLOPOW1       0x05
#define CJC8988_CHIPLOPOW2       0x06

#define CJC8988_ANAVOLMANAG      0x07

#define CJC8988_MASTERMODE       0x08
/* ADC */
#define CJC8988_ADCCONTROL1      0x09
#define CJC8988_ADCCONTROL2      0x0a
#define CJC8988_ADCCONTROL3      0x0b
#define CJC8988_ADCCONTROL4      0x0c
#define CJC8988_ADCCONTROL5      0x0d
#define CJC8988_ADCCONTROL6      0x0e
#define CJC8988_ADCCONTROL7      0x0f
#define CJC8988_ADCCONTROL8      0x10
#define CJC8988_ADCCONTROL9      0x11
#define CJC8988_ADCCONTROL10     0x12
#define CJC8988_ADCCONTROL11     0x13
#define CJC8988_ADCCONTROL12     0x14
#define CJC8988_ADCCONTROL13     0x15
#define CJC8988_ADCCONTROL14     0x16
/* DAC */
#define CJC8988_DACCONTROL1      0x17
#define CJC8988_DACCONTROL2      0x18
#define CJC8988_DACCONTROL3      0x19
#define CJC8988_DACCONTROL4      0x1a
#define CJC8988_DACCONTROL5      0x1b
#define CJC8988_DACCONTROL6      0x1c
#define CJC8988_DACCONTROL7      0x1d
#define CJC8988_DACCONTROL8      0x1e
#define CJC8988_DACCONTROL9      0x1f
#define CJC8988_DACCONTROL10     0x20
#define CJC8988_DACCONTROL11     0x21
#define CJC8988_DACCONTROL12     0x22
#define CJC8988_DACCONTROL13     0x23
#define CJC8988_DACCONTROL14     0x24
#define CJC8988_DACCONTROL15     0x25
#define CJC8988_DACCONTROL16     0x26
#define CJC8988_DACCONTROL17     0x27
#define CJC8988_DACCONTROL18     0x28
#define CJC8988_DACCONTROL19     0x29
#define CJC8988_DACCONTROL20     0x2a
#define CJC8988_DACCONTROL21     0x2b
#define CJC8988_DACCONTROL22     0x2c
#define CJC8988_DACCONTROL23     0x2d
#define CJC8988_DACCONTROL24     0x2e
#define CJC8988_DACCONTROL25     0x2f
#define CJC8988_DACCONTROL26     0x30
#define CJC8988_DACCONTROL27     0x31
#define CJC8988_DACCONTROL28     0x32
#define CJC8988_DACCONTROL29     0x33
#define CJC8988_DACCONTROL30     0x34

/**
 * @brief Initialize CJC8988 codec chip
 *
 * @param cfg configuration of CJC8988
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t cjc8988_init(audio_hal_codec_config_t *cfg);

/**
 * @brief Deinitialize CJC8988 codec chip
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t cjc8988_deinit(void);

/**
 * @brief Configure CJC8988 I2S format
 *
 * @param mod:  set ADC or DAC or both
 * @param cfg:   CJC8988 I2S format
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t cjc8988_config_fmt(es_module_t mod, es_i2s_fmt_t cfg);

/**
 * @brief Configure I2s clock in MSATER mode
 *
 * @param cfg:  set bits clock and WS clock
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t cjc8988_i2s_config_clock(es_i2s_clock_t cfg);

/**
 * @brief Configure CJC8988 data sample bits
 *
 * @param mode:  set ADC or DAC or both
 * @param bit_per_sample:  bit number of per sample
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t cjc8988_set_bits_per_sample(es_module_t mode, es_bits_length_t bit_per_sample);

/**
 * @brief  Start CJC8988 codec chip
 *
 * @param mode:  set ADC or DAC or both
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t cjc8988_start(es_module_t mode);

/**
 * @brief  Stop CJC8988 codec chip
 *
 * @param mode:  set ADC or DAC or both
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t cjc8988_stop(es_module_t mode);

/**
 * @brief  Set voice volume
 *
 * @param volume:  voice volume (0~100)
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t cjc8988_set_voice_volume(int volume);

/**
 * @brief Get voice volume
 *
 * @param[out] *volume:  voice volume (0~100)
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t cjc8988_get_voice_volume(int *volume);

/**
 * @brief Configure CJC8988 DAC mute or not. Basically you can use this function to mute the output or unmute
 *
 * @param enable enable(1) or disable(0)
 *
 * @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t cjc8988_set_voice_mute(bool enable);

/**
 * @brief Get CJC8988 DAC mute status
 *
 *  @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t cjc8988_get_voice_mute(void);

/**
 * @brief Set CJC8988 mic gain
 *
 * @param gain db of mic gain
 *
 * @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t cjc8988_set_mic_gain(es_mic_gain_t gain);

/**
 * @brief Set CJC8988 adc input mode
 *
 * @param input adc input mode
 *
 * @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t cjc8988_config_adc_input(es_adc_input_t input);

/**
 * @brief Set CJC8988 dac output mode
 *
 * @param output dac output mode
 *
 * @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t cjc8988_config_dac_output(es_dac_output_t output);

/**
 * @brief Write CJC8988 register
 *
 * @param reg_add address of register
 * @param data data of register
 *
 * @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t cjc8988_write_reg(uint8_t reg_add, uint8_t data);

/**
 * @brief Print all CJC8988 registers
 *
 * @return
 *     - void
 */
void cjc8988_read_all();

/**
 * @brief Configure CJC8988 codec mode and I2S interface
 *
 * @param mode codec mode
 * @param iface I2S config
 *
 * @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t cjc8988_config_i2s(audio_hal_codec_mode_t mode, audio_hal_codec_i2s_iface_t *iface);

/**
 * @brief Control CJC8988 codec chip
 *
 * @param mode codec mode
 * @param ctrl_state start or stop decode or encode progress
 *
 * @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t cjc8988_ctrl_state(audio_hal_codec_mode_t mode, audio_hal_ctrl_t ctrl_state);

/**
 * @brief Set CJC8988 PA power
 *
 * @param enable true for enable PA power, false for disable PA power
 *
 * @return
 *      - void
 */
void cjc8988_pa_power(bool enable);

#ifdef __cplusplus
}
#endif

#endif //__CJC8988_H__
