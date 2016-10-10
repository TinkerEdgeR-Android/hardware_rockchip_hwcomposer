/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_DRMHWCGRALLOC_H_
#define ANDROID_DRMHWCGRALLOC_H_

#include <stdint.h>

enum {
#if RK_DRM_HWC
  GRALLOC_MODULE_PERFORM_GET_DRM_FD                = 0x08000002,
  GRALLOC_MODULE_PERFORM_GET_HADNLE_PRIME_FD       = 0x08100002,
  GRALLOC_MODULE_PERFORM_GET_HADNLE_ATTRIBUTES     = 0x08100004,
  GRALLOC_MODULE_PERFORM_GET_INTERNAL_FORMAT       = 0x08100006,
#endif

  /* perform(const struct gralloc_module_t *mod,
   *	   int op,
   *	   int drm_fd,
   *	   buffer_handle_t buffer,
   *	   struct hwc_drm_bo *bo);
   */
  GRALLOC_MODULE_PERFORM_DRM_IMPORT = 0xffeeff00,

  /* perform(const struct gralloc_module_t *mod,
   *	   int op,
   *	   buffer_handle_t buffer,
   *	   void (*free_callback)(void *),
   *	   void *priv);
   */
  GRALLOC_MODULE_PERFORM_SET_IMPORTER_PRIVATE = 0xffeeff01,

  /* perform(const struct gralloc_module_t *mod,
   *	   int op,
   *	   buffer_handle_t buffer,
   *	   void (*free_callback)(void *),
   *	   void **priv);
   */
  GRALLOC_MODULE_PERFORM_GET_IMPORTER_PRIVATE = 0xffeeff02,

  /* perform(const struct gralloc_module_t *mod,
   *     int op,
   *     buffer_handle_t buffer,
   *     int *usage);
   */
  GRALLOC_MODULE_PERFORM_GET_USAGE = 0x0feeff03,
};

typedef struct hwc_drm_bo {
  uint32_t width;
  uint32_t height;
  uint32_t format; /* DRM_FORMAT_* from drm_fourcc.h */
  uint32_t pitches[4];
  uint32_t offsets[4];
  uint32_t gem_handles[4];
  uint32_t fb_id;
  int acquire_fence_fd;
  void *priv;
} hwc_drm_bo_t;

#endif  // ANDROID_DRMHWCGRALLOC_H_
