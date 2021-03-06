// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef OZONE_IMPL_OZONE_PLATFORM_WAYLAND_H_
#define OZONE_IMPL_OZONE_PLATFORM_WAYLAND_H_

#include "ui/events/ozone/event_factory_ozone.h"
#include "ui/ozone/ozone_platform.h"
#include "ozone/impl/desktop_factory_wayland.h"
#include "ozone/impl/ozone_display.h"

namespace ui {

// OzonePlatform for Wayland
//
// This platform is Linux with the wayland display server.
class OzonePlatformWayland : public OzonePlatform {
 public:
  OzonePlatformWayland();
  virtual ~OzonePlatformWayland();

  virtual gfx::SurfaceFactoryOzone* GetSurfaceFactoryOzone() OVERRIDE;
  virtual ui::EventFactoryOzone* GetEventFactoryOzone() OVERRIDE;

 private:
  ozonewayland::OzoneDisplay surface_factory_ozone_;

  // TODO: Use EventFactoryOzone. This is a stub that does nothing.
  EventFactoryOzone event_factory_ozone_;

#if defined(TOOLKIT_VIEWS) && !defined(OS_CHROMEOS)
  ozonewayland::DesktopFactoryWayland desktop_factory_ozone_;
#endif

  DISALLOW_COPY_AND_ASSIGN(OzonePlatformWayland);
};

// Constructor hook for use in ozone_platform_list.cc
OzonePlatform* CreateOzonePlatformWayland();

}  // namespace ui

#endif  // OZONE_IMPL_OZONE_PLATFORM_WAYLAND_H_
