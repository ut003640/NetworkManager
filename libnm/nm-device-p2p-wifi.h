/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright 2007 - 2008 Novell, Inc.
 * Copyright 2007 - 2018 Red Hat, Inc.
 */

#ifndef __NM_DEVICE_P2P_WIFI_H__
#define __NM_DEVICE_P2P_WIFI_H__

#if !defined (__NETWORKMANAGER_H_INSIDE__) && !defined (NETWORKMANAGER_COMPILATION)
#error "Only <NetworkManager.h> can be included directly."
#endif

#include "nm-device.h"

G_BEGIN_DECLS

#define NM_TYPE_DEVICE_P2P_WIFI            (nm_device_p2p_wifi_get_type ())
#define NM_DEVICE_P2P_WIFI(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), NM_TYPE_DEVICE_P2P_WIFI, NMDeviceP2PWifi))
#define NM_DEVICE_P2P_WIFI_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), NM_TYPE_DEVICE_P2P_WIFI, NMDeviceP2PWifiClass))
#define NM_IS_DEVICE_P2P_WIFI(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NM_TYPE_DEVICE_P2P_WIFI))
#define NM_IS_DEVICE_P2P_WIFI_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NM_TYPE_DEVICE_P2P_WIFI))
#define NM_DEVICE_P2P_WIFI_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), NM_TYPE_DEVICE_P2P_WIFI, NMDeviceP2PWifiClass))

#define NM_DEVICE_P2P_WIFI_HW_ADDRESS          "hw-address"
#define NM_DEVICE_P2P_WIFI_GROUP_OWNER         "group-owner"
#define NM_DEVICE_P2P_WIFI_PEERS               "peers"
#define NM_DEVICE_P2P_WIFI_WFDIES              "wfdies"

/**
 * NMDeviceP2PWifi:
 */
struct _NMDeviceP2PWifi {
	NMDevice parent;
};

typedef struct {
	NMDeviceClass parent;

	/* Signals */
	void (*peer_added) (NMDeviceP2PWifi *device, NMP2PPeer *peer);
	void (*peer_removed) (NMDeviceP2PWifi *device, NMP2PPeer *peer);

	/*< private >*/
	gpointer padding[4];
} NMDeviceP2PWifiClass;

GType nm_device_p2p_wifi_get_type (void);

const char *             nm_device_p2p_wifi_get_hw_address   (NMDeviceP2PWifi *device);
gboolean                 nm_device_p2p_wifi_get_group_owner  (NMDeviceP2PWifi *device);

#if 0
gboolean                 nm_device_p2p_wifi_get_wfdies  (NMDeviceP2PWifi *device);
#endif

NMP2PPeer *              nm_device_p2p_wifi_get_peer_by_path (NMDeviceP2PWifi *device,
                                                              const char *path);

const GPtrArray *        nm_device_p2p_wifi_get_peers        (NMDeviceP2PWifi *device);


G_END_DECLS

#endif /* __NM_DEVICE_P2P_WIFI_H__ */
