/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright (C) 2004 - 2017 Red Hat, Inc.
 * Copyright (C) 2006 - 2008 Novell, Inc.
 */

#ifndef __NM_WIFI_AP_H__
#define __NM_WIFI_AP_H__

#include "nm-dbus-object.h"
#include "nm-dbus-interface.h"
#include "nm-connection.h"
#include "libnm-base/nm-base.h"

#define NM_TYPE_WIFI_AP            (nm_wifi_ap_get_type())
#define NM_WIFI_AP(obj)            (_NM_G_TYPE_CHECK_INSTANCE_CAST((obj), NM_TYPE_WIFI_AP, NMWifiAP))
#define NM_WIFI_AP_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), NM_TYPE_WIFI_AP, NMWifiAPClass))
#define NM_IS_WIFI_AP(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), NM_TYPE_WIFI_AP))
#define NM_IS_WIFI_AP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), NM_TYPE_WIFI_AP))
#define NM_WIFI_AP_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj), NM_TYPE_WIFI_AP, NMWifiAPClass))

#define NM_WIFI_AP_FLAGS       "flags"
#define NM_WIFI_AP_WPA_FLAGS   "wpa-flags"
#define NM_WIFI_AP_RSN_FLAGS   "rsn-flags"
#define NM_WIFI_AP_SSID        "ssid"
#define NM_WIFI_AP_FREQUENCY   "frequency"
#define NM_WIFI_AP_HW_ADDRESS  "hw-address"
#define NM_WIFI_AP_MODE        "mode"
#define NM_WIFI_AP_MAX_BITRATE "max-bitrate"
#define NM_WIFI_AP_BANDWIDTH   "bandwidth"
#define NM_WIFI_AP_STRENGTH    "strength"
#define NM_WIFI_AP_LAST_SEEN   "last-seen"

typedef struct {
    NMDBusObject             parent;
    NMDevice                *wifi_device;
    CList                    aps_lst;
    NMRefString             *_supplicant_path;
    struct _NMWifiAPPrivate *_priv;
} NMWifiAP;

struct _NMSupplicantBssInfo;

typedef struct _NMWifiAPClass NMWifiAPClass;

GType nm_wifi_ap_get_type(void);

NMWifiAP *nm_wifi_ap_new_from_properties(const struct _NMSupplicantBssInfo *bss_info);
NMWifiAP *nm_wifi_ap_new_fake_from_connection(NMConnection *connection);

gboolean nm_wifi_ap_update_from_properties(NMWifiAP                          *ap,
                                           const struct _NMSupplicantBssInfo *bss_info,
                                           gboolean                          update_signal);

gboolean nm_wifi_ap_check_compatible(NMWifiAP *self, NMConnection *connection);

gboolean nm_wifi_ap_complete_connection(NMWifiAP     *self,
                                        NMConnection *connection,
                                        gboolean      lock_bssid,
                                        GError      **error);

static inline NMRefString *
nm_wifi_ap_get_supplicant_path(NMWifiAP *ap)
{
    g_return_val_if_fail(NM_IS_WIFI_AP(ap), NULL);

    return ap->_supplicant_path;
}

GBytes                *nm_wifi_ap_get_ssid(const NMWifiAP *ap);
gboolean               nm_wifi_ap_set_ssid(NMWifiAP *ap, GBytes *ssid);
const char            *nm_wifi_ap_get_address(const NMWifiAP *ap);
gboolean               nm_wifi_ap_set_address(NMWifiAP *ap, const char *addr);
gboolean               nm_wifi_ap_set_address_bin(NMWifiAP *ap, const NMEtherAddr *addr);
_NM80211Mode           nm_wifi_ap_get_mode(NMWifiAP *ap);
gboolean               nm_wifi_ap_is_hotspot(NMWifiAP *ap);
gint8                  nm_wifi_ap_get_strength(NMWifiAP *ap);
gboolean               nm_wifi_ap_set_strength(NMWifiAP *ap, gint8 strength);
guint32                nm_wifi_ap_get_freq(NMWifiAP *ap);
gboolean               nm_wifi_ap_set_freq(NMWifiAP *ap, guint32 freq);
guint32                nm_wifi_ap_get_max_bitrate(NMWifiAP *ap);
gboolean               nm_wifi_ap_set_max_bitrate(NMWifiAP *ap, guint32 bitrate);
guint32                nm_wifi_ap_get_bandwidth(NMWifiAP *ap);
gboolean               nm_wifi_ap_set_bandwidth(NMWifiAP *ap, guint32 bandwidth);
gboolean               nm_wifi_ap_get_fake(const NMWifiAP *ap);
gboolean               nm_wifi_ap_set_fake(NMWifiAP *ap, gboolean fake);
NM80211ApFlags         nm_wifi_ap_get_flags(const NMWifiAP *self);
gboolean               nm_wifi_ap_get_metered(const NMWifiAP *self);
NM80211ApSecurityFlags nm_wifi_ap_get_wpa_flags(const NMWifiAP *self);
NM80211ApSecurityFlags nm_wifi_ap_get_rsn_flags(const NMWifiAP *self);

const char *
nm_wifi_ap_to_string(const NMWifiAP *self, char *str_buf, gulong buf_len, gint64 now_msec);

const char **nm_wifi_aps_get_paths(const CList *aps_lst_head, gboolean include_without_ssid);

NMWifiAP *nm_wifi_aps_find_first_compatible(const CList *aps_lst_head, NMConnection *connection);

NMWifiAP *nm_wifi_ap_lookup_for_device(NMDevice *device, const char *exported_path);

#endif /* __NM_WIFI_AP_H__ */
