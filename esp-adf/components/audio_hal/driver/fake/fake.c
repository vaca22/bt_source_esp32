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

#include <string.h>
#include "esp_log.h"
#include "i2c_bus.h"
#include "fake.h"
#include "board_pins_config.h"



static const char *ES_TAG = "ES8388_DRIVER";
static i2c_bus_handle_t i2c_handle;

#define ES_ASSERT(a, format, b, ...) \
    if ((a) != 0) { \
        ESP_LOGE(ES_TAG, format, ##__VA_ARGS__); \
        return b;\
    }

audio_hal_func_t AUDIO_CODEC_FAKE_DEFAULT_HANDLE = {
    .audio_codec_initialize = es8388_init,
    .audio_codec_deinitialize = es8388_deinit,
    .audio_codec_ctrl = es8388_ctrl_state,
    .audio_codec_config_iface = es8388_config_i2s,
    .audio_codec_set_mute = es8388_set_voice_mute,
    .audio_codec_set_volume = es8388_set_voice_volume,
    .audio_codec_get_volume = es8388_get_voice_volume,
    .audio_hal_lock = NULL,
    .handle = NULL,
};

static esp_err_t es_write_reg(uint8_t slave_addr, uint8_t reg_add, uint8_t data)
{
    return ESP_OK;
}

static esp_err_t es_read_reg(uint8_t reg_add, uint8_t *p_data)
{
    return ESP_OK;
}

static int i2c_init()
{

    return ESP_OK;
}

void es8388_read_all()
{

}

esp_err_t es8388_write_reg(uint8_t reg_add, uint8_t data)
{
    return ESP_OK;
}

/**
 * @brief Configure ES8388 ADC and DAC volume. Basicly you can consider this as ADC and DAC gain
 *
 * @param mode:             set ADC or DAC or all
 * @param volume:           -96 ~ 0              for example Es8388SetAdcDacVolume(ES_MODULE_ADC, 30, 6); means set ADC volume -30.5db
 * @param dot:              whether include 0.5. for example Es8388SetAdcDacVolume(ES_MODULE_ADC, 30, 4); means set ADC volume -30db
 *
 * @return
 *     - (-1) Parameter error
 *     - (0)   Success
 */
static int es8388_set_adc_dac_volume(int mode, int volume, int dot)
{

    return ESP_OK;
}


/**
 * @brief Power Management
 *
 * @param mod:      if ES_POWER_CHIP, the whole chip including ADC and DAC is enabled
 * @param enable:   false to disable true to enable
 *
 * @return
 *     - (-1)  Error
 *     - (0)   Success
 */
esp_err_t es8388_start(es_module_t mode)
{
    return ESP_OK;
}

/**
 * @brief Power Management
 *
 * @param mod:      if ES_POWER_CHIP, the whole chip including ADC and DAC is enabled
 * @param enable:   false to disable true to enable
 *
 * @return
 *     - (-1)  Error
 *     - (0)   Success
 */
esp_err_t es8388_stop(es_module_t mode)
{
    return ESP_OK;
}


/**
 * @brief Config I2s clock in MSATER mode
 *
 * @param cfg.sclkDiv:      generate SCLK by dividing MCLK in MSATER mode
 * @param cfg.lclkDiv:      generate LCLK by dividing MCLK in MSATER mode
 *
 * @return
 *     - (-1)  Error
 *     - (0)   Success
 */
esp_err_t es8388_i2s_config_clock(es_i2s_clock_t cfg)
{
    return ESP_OK;
}

esp_err_t es8388_deinit(void)
{
    return ESP_OK;
}

/**
 * @return
 *     - (-1)  Error
 *     - (0)   Success
 */
esp_err_t es8388_init(audio_hal_codec_config_t *cfg)
{
    return ESP_OK;
}

/**
 * @brief Configure ES8388 I2S format
 *
 * @param mode:           set ADC or DAC or all
 * @param bitPerSample:   see Es8388I2sFmt
 *
 * @return
 *     - (-1) Error
 *     - (0)  Success
 */
esp_err_t es8388_config_fmt(es_module_t mode, es_i2s_fmt_t fmt)
{
    return ESP_OK;
}

/**
 * @param volume: 0 ~ 100
 *
 * @return
 *     - (-1)  Error
 *     - (0)   Success
 */
esp_err_t es8388_set_voice_volume(int volume)
{
    return ESP_OK;
}

/**
 *
 * @return
 *           volume
 */
esp_err_t es8388_get_voice_volume(int *volume)
{
    return ESP_OK;
}

/**
 * @brief Configure ES8388 data sample bits
 *
 * @param mode:             set ADC or DAC or all
 * @param bitPerSample:   see BitsLength
 *
 * @return
 *     - (-1) Parameter error
 *     - (0)   Success
 */
esp_err_t es8388_set_bits_per_sample(es_module_t mode, es_bits_length_t bits_length)
{
    return ESP_OK;
}

/**
 * @brief Configure ES8388 DAC mute or not. Basically you can use this function to mute the output or unmute
 *
 * @param enable: enable or disable
 *
 * @return
 *     - (-1) Parameter error
 *     - (0)   Success
 */
esp_err_t es8388_set_voice_mute(bool enable)
{
    return ESP_OK;
}

esp_err_t es8388_get_voice_mute(void)
{
    return ESP_OK;
}

/**
 * @param gain: Config DAC Output
 *
 * @return
 *     - (-1) Parameter error
 *     - (0)   Success
 */
esp_err_t es8388_config_dac_output(int output)
{
    return ESP_OK;
}

/**
 * @param gain: Config ADC input
 *
 * @return
 *     - (-1) Parameter error
 *     - (0)   Success
 */
esp_err_t es8388_config_adc_input(es_adc_input_t input)
{
    return ESP_OK;
}

/**
 * @param gain: see es_mic_gain_t
 *
 * @return
 *     - (-1) Parameter error
 *     - (0)   Success
 */
esp_err_t es8388_set_mic_gain(es_mic_gain_t gain)
{
    return ESP_OK;
}

int es8388_ctrl_state(audio_hal_codec_mode_t mode, audio_hal_ctrl_t ctrl_state)
{
    return ESP_OK;
}

esp_err_t es8388_config_i2s(audio_hal_codec_mode_t mode, audio_hal_codec_i2s_iface_t *iface)
{
    return ESP_OK;
}

void es8388_pa_power(bool enable)
{

}
