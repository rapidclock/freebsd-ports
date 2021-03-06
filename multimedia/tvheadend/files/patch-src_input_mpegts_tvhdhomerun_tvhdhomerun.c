From 6f494ce84b77de092447dbb793eca8cc7b5296ee Mon Sep 17 00:00:00 2001
From: Michael Marley <michael@michaelmarley.com>
Date: Wed, 26 Jun 2019 19:35:50 -0400
Subject: [PATCH] Fix compilation with libhdhomerun 20190621

They renamed the symbol that was used to determine whether the
"hdhomerun_discover_find_devices_custom" needed to be aliased,
causing an FTBFS.  Instead, recognize both the old and new symbols.
---
 src/input/mpegts/tvhdhomerun/tvhdhomerun.c | 3 ++-
 1 file changed, 2 insertions(+), 1 deletion(-)

diff --git a/src/input/mpegts/tvhdhomerun/tvhdhomerun.c b/src/input/mpegts/tvhdhomerun/tvhdhomerun.c
index 58dec51ab3..18068faf5d 100644
--- src/input/mpegts/tvhdhomerun/tvhdhomerun.c
+++ src/input/mpegts/tvhdhomerun/tvhdhomerun.c
@@ -32,7 +32,8 @@
 
 #include "config.h"
 
-#ifdef HDHOMERUN_TAG_DEVICE_AUTH_BIN
+#if defined(HDHOMERUN_TAG_DEVICE_AUTH_BIN) \
+           || defined(HDHOMERUN_TAG_DEVICE_AUTH_BIN_DEPRECATED)
 #define hdhomerun_discover_find_devices_custom \
            hdhomerun_discover_find_devices_custom_v2
 #endif
