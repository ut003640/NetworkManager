/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright (C) 2010 - 2018 Red Hat, Inc.
 */

#ifndef __NM_META_SETTING_DESC_H__
#define __NM_META_SETTING_DESC_H__

#include "libnm-glib-aux/nm-obj.h"
#include "nm-meta-setting-base.h"
#include "libnm-base/nm-ethtool-base.h"

struct _NMDevice;

#define NM_META_TEXT_HIDDEN N_("<hidden>")

#define NM_META_TEXT_PROMPT_ADSL_PROTO N_("Protocol")
#define NM_META_TEXT_PROMPT_ADSL_PROTO_CHOICES                            \
    "(" NM_SETTING_ADSL_PROTOCOL_PPPOA "/" NM_SETTING_ADSL_PROTOCOL_PPPOE \
    "/" NM_SETTING_ADSL_PROTOCOL_IPOATM ")"

#define NM_META_TEXT_PROMPT_ADSL_ENCAP N_("ADSL encapsulation")
#define NM_META_TEXT_PROMPT_ADSL_ENCAP_CHOICES \
    "(" NM_SETTING_ADSL_ENCAPSULATION_VCMUX "/" NM_SETTING_ADSL_ENCAPSULATION_LLC ") [none]"

#define NM_META_TEXT_PROMPT_CON_TYPE N_("Connection type")
#define NM_META_TEXT_PROMPT_IFNAME   N_("Interface name")
#define NM_META_TEXT_PROMPT_VPN_TYPE N_("VPN type")
#define NM_META_TEXT_PROMPT_MASTER   N_("Master")

#define NM_META_TEXT_PROMPT_IB_MODE N_("Transport mode")
#define NM_META_TEXT_WORD_DATAGRAM  "datagram"
#define NM_META_TEXT_WORD_CONNECTED "connected"
#define NM_META_TEXT_PROMPT_IB_MODE_CHOICES                        \
    "(" NM_META_TEXT_WORD_DATAGRAM "/" NM_META_TEXT_WORD_CONNECTED \
    ") [" NM_META_TEXT_WORD_DATAGRAM "]"

#define NM_META_TEXT_PROMPT_BT_TYPE N_("Bluetooth type")
#define NM_META_TEXT_WORD_PANU      "panu"
#define NM_META_TEXT_WORD_NAP       "nap"
#define NM_META_TEXT_WORD_DUN_GSM   "dun-gsm"
#define NM_META_TEXT_WORD_DUN_CDMA  "dun-cdma"
#define NM_META_TEXT_PROMPT_BT_TYPE_CHOICES                                            \
    "(" NM_META_TEXT_WORD_PANU "/" NM_META_TEXT_WORD_NAP "/" NM_META_TEXT_WORD_DUN_GSM \
    "/" NM_META_TEXT_WORD_DUN_CDMA ") [" NM_META_TEXT_WORD_PANU "]"

#define NM_META_TEXT_PROMPT_BOND_MODE N_("Bonding mode")

#define NM_META_TEXT_PROMPT_BOND_MON_MODE N_("Bonding monitoring mode")
#define NM_META_TEXT_WORD_MIIMON          "miimon"
#define NM_META_TEXT_WORD_ARP             "arp"
#define NM_META_TEXT_PROMPT_BOND_MON_MODE_CHOICES \
    "(" NM_META_TEXT_WORD_MIIMON "/" NM_META_TEXT_WORD_ARP ") [" NM_META_TEXT_WORD_MIIMON "]"

#define NM_META_TEXT_PROMPT_WIFI_MODE N_("Wi-Fi mode")
#define NM_META_TEXT_WORD_INFRA       "infrastructure"
#define NM_META_TEXT_WORD_AP          "ap"
#define NM_META_TEXT_WORD_ADHOC       "adhoc"
#define NM_META_TEXT_WORD_MESH        "mesh"
#define NM_META_TEXT_PROMPT_WIFI_MODE_CHOICES                                        \
    "(" NM_META_TEXT_WORD_INFRA "/" NM_META_TEXT_WORD_AP "/" NM_META_TEXT_WORD_ADHOC \
    "/" NM_META_TEXT_WORD_MESH ") [" NM_META_TEXT_WORD_INFRA "]"

#define NM_META_TEXT_PROMPT_TUN_MODE N_("Tun mode")
#define NM_META_TEXT_WORD_TUN        "tun"
#define NM_META_TEXT_WORD_TAP        "tap"
#define NM_META_TEXT_PROMPT_TUN_MODE_CHOICES \
    "(" NM_META_TEXT_WORD_TUN "/" NM_META_TEXT_WORD_TAP ") [" NM_META_TEXT_WORD_TUN "]"

#define NM_META_TEXT_PROMPT_IP_TUNNEL_MODE N_("IP Tunnel mode")

#define NM_META_TEXT_PROMPT_IPVLAN_MODE N_("IPVLAN mode")

#define NM_META_TEXT_PROMPT_MACVLAN_MODE N_("MACVLAN mode")

#define NM_META_TEXT_PROMPT_MACSEC_MODE N_("MACsec mode")
#define NM_META_TEXT_WORD_PSK           "psk"
#define NM_META_TEXT_WORD_EAP           "eap"
#define NM_META_TEXT_PROMPT_MACSEC_MODE_CHOICES \
    "(" NM_META_TEXT_WORD_PSK "/" NM_META_TEXT_WORD_EAP ")"

#define NM_META_TEXT_PROMPT_PROXY_METHOD N_("Proxy method")
#define NM_META_TEXT_WORD_NONE           "none"
#define NM_META_TEXT_WORD_AUTO           "auto"
#define NM_META_TEXT_PROMPT_PROXY_METHOD_CHOICES \
    "(" NM_META_TEXT_WORD_NONE "/" NM_META_TEXT_WORD_AUTO ") [" NM_META_TEXT_WORD_NONE "]"

typedef enum {
    NM_META_COLOR_NONE = 0,
    NM_META_COLOR_CONNECTION_ACTIVATED,
    NM_META_COLOR_CONNECTION_ACTIVATING,
    NM_META_COLOR_CONNECTION_DISCONNECTING,
    NM_META_COLOR_CONNECTION_INVISIBLE,
    NM_META_COLOR_CONNECTION_EXTERNAL,
    NM_META_COLOR_CONNECTION_UNKNOWN,
    NM_META_COLOR_CONNECTION_DEPRECATED,
    NM_META_COLOR_CONNECTIVITY_FULL,
    NM_META_COLOR_CONNECTIVITY_LIMITED,
    NM_META_COLOR_CONNECTIVITY_NONE,
    NM_META_COLOR_CONNECTIVITY_PORTAL,
    NM_META_COLOR_CONNECTIVITY_UNKNOWN,
    NM_META_COLOR_DEVICE_ACTIVATED,
    NM_META_COLOR_DEVICE_ACTIVATING,
    NM_META_COLOR_DEVICE_DISCONNECTED,
    NM_META_COLOR_DEVICE_FIRMWARE_MISSING,
    NM_META_COLOR_DEVICE_PLUGIN_MISSING,
    NM_META_COLOR_DEVICE_UNAVAILABLE,
    NM_META_COLOR_DEVICE_DISABLED,
    NM_META_COLOR_DEVICE_EXTERNAL,
    NM_META_COLOR_DEVICE_UNKNOWN,
    NM_META_COLOR_MANAGER_RUNNING,
    NM_META_COLOR_MANAGER_STARTING,
    NM_META_COLOR_MANAGER_STOPPED,
    NM_META_COLOR_PERMISSION_AUTH,
    NM_META_COLOR_PERMISSION_NO,
    NM_META_COLOR_PERMISSION_UNKNOWN,
    NM_META_COLOR_PERMISSION_YES,
    NM_META_COLOR_PROMPT,
    NM_META_COLOR_STATE_ASLEEP,
    NM_META_COLOR_STATE_CONNECTED_GLOBAL,
    NM_META_COLOR_STATE_CONNECTED_LOCAL,
    NM_META_COLOR_STATE_CONNECTED_SITE,
    NM_META_COLOR_STATE_CONNECTING,
    NM_META_COLOR_STATE_DISCONNECTED,
    NM_META_COLOR_STATE_DISCONNECTING,
    NM_META_COLOR_STATE_UNKNOWN,
    NM_META_COLOR_WIFI_SIGNAL_EXCELLENT,
    NM_META_COLOR_WIFI_SIGNAL_FAIR,
    NM_META_COLOR_WIFI_SIGNAL_GOOD,
    NM_META_COLOR_WIFI_SIGNAL_POOR,
    NM_META_COLOR_WIFI_SIGNAL_UNKNOWN,
    NM_META_COLOR_WIFI_DEPRECATED,
    NM_META_COLOR_DISABLED,
    NM_META_COLOR_ENABLED,
    _NM_META_COLOR_NUM
} NMMetaColor;

typedef enum {
    NM_META_ACCESSOR_MODIFIER_SET,
    NM_META_ACCESSOR_MODIFIER_ADD,
    NM_META_ACCESSOR_MODIFIER_DEL,
} NMMetaAccessorModifier;

typedef enum {
    NM_META_ACCESSOR_GET_TYPE_PRETTY,
    NM_META_ACCESSOR_GET_TYPE_PARSABLE,
    NM_META_ACCESSOR_GET_TYPE_COLOR,
} NMMetaAccessorGetType;

typedef enum {
    NM_META_ACCESSOR_SETTING_INIT_TYPE_DEFAULT,
    NM_META_ACCESSOR_SETTING_INIT_TYPE_CLI,
} NMMetaAccessorSettingInitType;

typedef enum {
    NM_META_ACCESSOR_GET_FLAGS_NONE         = 0,
    NM_META_ACCESSOR_GET_FLAGS_ACCEPT_STRV  = (1LL << 0),
    NM_META_ACCESSOR_GET_FLAGS_SHOW_SECRETS = (1LL << 1),
} NMMetaAccessorGetFlags;

typedef enum {
    NM_META_ACCESSOR_GET_OUT_FLAGS_NONE = 0,
    NM_META_ACCESSOR_GET_OUT_FLAGS_STRV = (1LL << 0),

    /* the property allows one to be hidden, if and only if, it's value is set to the
     * default. This should only be set by new properties, to preserve behavior
     * of old properties, which were always printed. */
    NM_META_ACCESSOR_GET_OUT_FLAGS_HIDE = (1LL << 1),
} NMMetaAccessorGetOutFlags;

typedef enum {
    NM_META_PROPERTY_TYP_FLAG_ENUM_GET_PRETTY_NUMERIC       = (1LL << 0),
    NM_META_PROPERTY_TYP_FLAG_ENUM_GET_PRETTY_NUMERIC_HEX   = (1LL << 1),
    NM_META_PROPERTY_TYP_FLAG_ENUM_GET_PRETTY_TEXT          = (1LL << 2),
    NM_META_PROPERTY_TYP_FLAG_ENUM_GET_PRETTY_TEXT_L10N     = (1LL << 3),
    NM_META_PROPERTY_TYP_FLAG_ENUM_GET_PARSABLE_NUMERIC     = (1LL << 4),
    NM_META_PROPERTY_TYP_FLAG_ENUM_GET_PARSABLE_NUMERIC_HEX = (1LL << 5),
    NM_META_PROPERTY_TYP_FLAG_ENUM_GET_PARSABLE_TEXT        = (1LL << 6),
} NMMetaPropertyTypFlags;

typedef enum {
    NM_META_PROPERTY_TYPE_MAC_MODE_DEFAULT,
    NM_META_PROPERTY_TYPE_MAC_MODE_CLONED_ETHERNET,
    NM_META_PROPERTY_TYPE_MAC_MODE_CLONED_WIFI,
    NM_META_PROPERTY_TYPE_MAC_MODE_INFINIBAND,
    NM_META_PROPERTY_TYPE_MAC_MODE_WPAN,
} NMMetaPropertyTypeMacMode;

typedef enum _nm_packed {
    NM_META_PROPERTY_TYPE_FORMAT_UNDEF = 0,
    NM_META_PROPERTY_TYPE_FORMAT_INT,
    NM_META_PROPERTY_TYPE_FORMAT_STRING,
    NM_META_PROPERTY_TYPE_FORMAT_ENUM,
    NM_META_PROPERTY_TYPE_FORMAT_SECRET_FLAGS,
    NM_META_PROPERTY_TYPE_FORMAT_BOOL,
    NM_META_PROPERTY_TYPE_FORMAT_TERNARY,
    NM_META_PROPERTY_TYPE_FORMAT_MAC,
    NM_META_PROPERTY_TYPE_FORMAT_IPV4,
    NM_META_PROPERTY_TYPE_FORMAT_IPV6,
    NM_META_PROPERTY_TYPE_FORMAT_IPV4_IPV6,
    NM_META_PROPERTY_TYPE_FORMAT_MTU,
    NM_META_PROPERTY_TYPE_FORMAT_BYTES,
    NM_META_PROPERTY_TYPE_FORMAT_PATH,
    NM_META_PROPERTY_TYPE_FORMAT_ETHTOOL,
    NM_META_PROPERTY_TYPE_FORMAT_MULTILIST,
    NM_META_PROPERTY_TYPE_FORMAT_OBJLIST,
    NM_META_PROPERTY_TYPE_FORMAT_OPTIONLIST,
    NM_META_PROPERTY_TYPE_FORMAT_DCB,
    NM_META_PROPERTY_TYPE_FORMAT_DCB_BOOL,
    NM_META_PROPERTY_TYPE_FORMAT_DCB_FLAGS,
} NMMetaPropertyTypeFormat;

typedef struct _NMMetaEnvironment           NMMetaEnvironment;
typedef struct _NMMetaType                  NMMetaType;
typedef struct _NMMetaAbstractInfo          NMMetaAbstractInfo;
typedef struct _NMMetaSettingInfoEditor     NMMetaSettingInfoEditor;
typedef struct _NMMetaPropertyInfo          NMMetaPropertyInfo;
typedef struct _NMMetaPropertyType          NMMetaPropertyType;
typedef struct _NMMetaPropertyTypData       NMMetaPropertyTypData;
typedef struct _NMMetaOperationContext      NMMetaOperationContext;
typedef struct _NMMetaNestedPropertyInfo    NMMetaNestedPropertyInfo;
typedef struct _NMMetaPropertyTypDataNested NMMetaPropertyTypDataNested;

/* this gives some context information for virtual functions.
 * This command actually violates layering, and should be considered
 * a hack. In the future, try to replace its use. */
struct _NMMetaOperationContext {
    NMConnection *connection;
};

struct _NMMetaPropertyType {
    /* should return a translated string */
    const char *(*describe_fcn)(const NMMetaPropertyInfo *property_info, char **out_to_free);

    gconstpointer (*get_fcn)(const NMMetaPropertyInfo  *property_info,
                             const NMMetaEnvironment   *environment,
                             gpointer                   environment_user_data,
                             NMSetting                 *setting,
                             NMMetaAccessorGetType      get_type,
                             NMMetaAccessorGetFlags     get_flags,
                             NMMetaAccessorGetOutFlags *out_flags,
                             gboolean                  *out_is_default,
                             gpointer                  *out_to_free);
    gboolean (*set_fcn)(const NMMetaPropertyInfo *property_info,
                        const NMMetaEnvironment  *environment,
                        gpointer                  environment_user_data,
                        NMSetting                *setting,
                        NMMetaAccessorModifier    modifier,
                        const char               *value,
                        GError                  **error);

    const char *const *(*values_fcn)(const NMMetaPropertyInfo *property_info, char ***out_to_free);

    const char *const *(*complete_fcn)(const NMMetaPropertyInfo     *property_info,
                                       const NMMetaEnvironment      *environment,
                                       gpointer                      environment_user_data,
                                       const NMMetaOperationContext *operation_context,
                                       const char                   *text,
                                       gboolean                     *out_complete_filename,
                                       char                       ***out_to_free);

    NMMetaPropertyTypeFormat doc_format;

    /* Whether set_fcn() supports the '-' modifier. That is, whether the property
     * is a list type. */
    bool set_supports_remove : 1;
};

struct _NMUtilsEnumValueInfo;

typedef union {
    gint64  i64;
    guint64 u64;
} NMMetaSignUnsignInt64;

typedef struct {
    const char           *nick;
    NMMetaSignUnsignInt64 value;
} NMMetaUtilsIntValueInfo;

struct _NMMetaPropertyTypData {
    union {
        struct {
            GType (*get_gtype)(void); /* note: only allowed for int/uint properties */
            int                                 min;
            int                                 max;
            const struct _NMUtilsEnumValueInfo *value_infos_get; /* nicks for get function */
            const struct _NMUtilsEnumValueInfo *value_infos;     /* nicks for set function */
            void (*pre_set_notify)(const NMMetaPropertyInfo *property_info,
                                   const NMMetaEnvironment  *environment,
                                   gpointer                  environment_user_data,
                                   NMSetting                *setting,
                                   int                       value);
        } gobject_enum;
        struct {
            NMMetaSignUnsignInt64          min;
            NMMetaSignUnsignInt64          max;
            guint                          base;
            const NMMetaUtilsIntValueInfo *value_infos;
        } gobject_int;
        struct {
            const char *(*validate_fcn)(const char *value, char **out_to_free, GError **error);
            bool handle_emptyunset : 1;
        } gobject_string;
        struct {
            bool legacy_format : 1;
        } gobject_bytes;
        struct {
            guint32 (*get_num_fcn_u32)(NMSetting *setting);
            guint (*get_num_fcn_u)(NMSetting *setting);
            void (*clear_all_fcn)(NMSetting *setting);

            /* some multilist properties distinguish between an empty list and
             * and unset. If this function pointer is set, certain behaviors come
             * into action to handle that. */
            void (*clear_emptyunset_fcn)(NMSetting *setting,
                                         gboolean   is_set /* or else set default */);

            gboolean (*add_fcn)(NMSetting *setting, const char *item);
            void (*add2_fcn)(NMSetting *setting, const char *item);
            const char *(*validate_fcn)(const char *item, GError **error);
            const char *(*validate2_fcn)(NMSetting *setting, const char *item, GError **error);
            void (*remove_by_idx_fcn_u32)(NMSetting *setting, guint32 idx);
            void (*remove_by_idx_fcn_u)(NMSetting *setting, guint idx);
            void (*remove_by_idx_fcn_s)(NMSetting *setting, int idx);
            gboolean (*remove_by_value_fcn)(NMSetting *setting, const char *item);
            bool strsplit_plain : 1;
            bool strsplit_with_spaces : 1;
        } multilist;
        struct {
            guint (*get_num_fcn)(NMSetting *setting);
            void (*obj_to_str_fcn)(NMMetaAccessorGetType get_type,
                                   NMSetting            *setting,
                                   guint                 idx,
                                   GString              *str);
            gboolean (*set_fcn)(NMSetting  *setting,
                                gboolean    do_add /* or else remove. */,
                                const char *value,
                                GError    **error);
            void (*clear_all_fcn)(NMSetting *setting);
            void (*remove_by_idx_fcn_u)(NMSetting *setting, guint idx);
            void (*remove_by_idx_fcn_s)(NMSetting *setting, int idx);
            bool delimit_pretty_with_semicolon : 1;
            bool strsplit_plain : 1;
        } objlist;
        struct {
            gboolean (*set_fcn)(NMSetting  *setting,
                                const char *option,
                                const char *value,
                                GError    **error);
            bool no_empty_value : 1;
        } optionlist;
        struct {
            guint32 (*get_fcn)(NMSetting *setting);
        } mtu;
        struct {
            NMSetting8021xSchemeType scheme_type;
        } cert_8021x;
        struct {
            NMMetaPropertyTypeMacMode mode;
        } mac;
        struct {
            guint (*get_fcn)(NMSettingDcb *setting, guint user_priority);
            void (*set_fcn)(NMSettingDcb *setting, guint id, guint value);
            guint max;
            guint other;
            bool  is_percent : 1;
        } dcb;
        struct {
            gboolean (*get_fcn)(NMSettingDcb *s_dcb, guint priority);
            void (*set_fcn)(NMSettingDcb *setting, guint user_priority, gboolean enabled);
            bool with_flow_control_flags : 1;
        } dcb_bool;
        struct {
            NMEthtoolID ethtool_id;
        } ethtool;
    } subtype;
    gboolean (*is_default_fcn)(NMSetting *setting);
    const char *const                 *values_static;
    const NMMetaPropertyTypDataNested *nested;
    NMMetaPropertyTypFlags             typ_flags;
    NMMetaPropertyTypeFormat           list_items_doc_format;
};

typedef enum {
    NM_META_PROPERTY_INF_FLAG_NONE     = 0x00,
    NM_META_PROPERTY_INF_FLAG_REQD     = 0x01, /* Don't ask to ask. */
    NM_META_PROPERTY_INF_FLAG_DONT_ASK = 0x02, /* Don't ask interactively by default */
    NM_META_PROPERTY_INF_FLAG_MULTI = 0x04, /* Ask multiple times, do an append instead of set. */
} NMMetaPropertyInfFlags;

enum {
    _NM_META_PROPERTY_TYPE_VPN_SERVICE_TYPE = 0,
    _NM_META_PROPERTY_TYPE_CONNECTION_TYPE  = 3,
};

#define nm_meta_property_info_connection_type                      \
    (nm_meta_setting_infos_editor[NM_META_SETTING_TYPE_CONNECTION] \
         .properties[_NM_META_PROPERTY_TYPE_CONNECTION_TYPE])
#define nm_meta_property_info_vpn_service_type              \
    (nm_meta_setting_infos_editor[NM_META_SETTING_TYPE_VPN] \
         .properties[_NM_META_PROPERTY_TYPE_VPN_SERVICE_TYPE])

struct _NMMetaPropertyInfo {
    union {
        NMObjBaseInst     parent;
        const NMMetaType *meta_type;
    };

    const NMMetaSettingInfoEditor *setting_info;

    const char *property_name;

    const char *property_alias;

    NMMetaPropertyInfFlags inf_flags;
    bool                   is_secret : 1;

    bool is_cli_option : 1;
    bool hide_if_default : 1;

    const char *prompt;

    const char *def_hint;

    const char *describe_doc;

    /* a non-translated but translatable static description (marked with N_()). */
    const char *describe_message;

    const NMMetaPropertyType    *property_type;
    const NMMetaPropertyTypData *property_typ_data;
};

typedef struct _NMMetaSettingValidPartItem {
    const NMMetaSettingInfoEditor *setting_info;
    bool                           mandatory;
} NMMetaSettingValidPartItem;

struct _NMMetaSettingInfoEditor {
    union {
        NMObjBaseInst     parent;
        const NMMetaType *meta_type;
    };
    const NMMetaSettingInfo         *general;
    const char                      *alias;
    const char                      *pretty_name;
    const NMMetaPropertyInfo *const *properties;
    guint                            properties_num;

    /* a NMConnection has a main type (connection.type), which is a
     * main NMSetting instance. Depending on the type, a connection
     * may have a list of other allowed settings.
     *
     * For example, a connection of type "vlan" may have settings
     * of type "connection", "vlan", and "wired".
     *
     * Some setting types a not a main type (NMSettingProxy). They
     * don't have valid_settings but are usually referenced by other
     * settings to be valid for them. */
    const NMMetaSettingValidPartItem *const *valid_parts;

    void (*setting_init_fcn)(const NMMetaSettingInfoEditor *setting_info,
                             NMSetting                     *setting,
                             NMMetaAccessorSettingInitType  init_type);
};

struct _NMMetaType {
    NMObjBaseClass parent;
    const char    *type_name;
    const char *(*get_name)(const NMMetaAbstractInfo *abstract_info, gboolean for_header);
    const NMMetaAbstractInfo *const *(*get_nested)(const NMMetaAbstractInfo *abstract_info,
                                                   guint                    *out_len,
                                                   gpointer                 *out_to_free);
    gconstpointer (*get_fcn)(const NMMetaAbstractInfo  *info,
                             const NMMetaEnvironment   *environment,
                             gpointer                   environment_user_data,
                             gpointer                   target,
                             gpointer                   target_data,
                             NMMetaAccessorGetType      get_type,
                             NMMetaAccessorGetFlags     get_flags,
                             NMMetaAccessorGetOutFlags *out_flags,
                             gboolean                  *out_is_default,
                             gpointer                  *out_to_free);
    const char *const *(*complete_fcn)(const NMMetaAbstractInfo     *info,
                                       const NMMetaEnvironment      *environment,
                                       gpointer                      environment_user_data,
                                       const NMMetaOperationContext *operation_context,
                                       const char                   *text,
                                       gboolean                     *out_complete_filename,
                                       char                       ***out_to_free);
};

struct _NMMetaAbstractInfo {
    union {
        NMObjBaseInst     parent;
        const NMMetaType *meta_type;
    };
};

extern const NMMetaType nm_meta_type_setting_info_editor;
extern const NMMetaType nm_meta_type_property_info;

extern const NMMetaSettingInfoEditor nm_meta_setting_infos_editor[_NM_META_SETTING_TYPE_NUM];

extern const NMMetaSettingValidPartItem *const nm_meta_setting_info_valid_parts_default[];

const NMMetaSettingValidPartItem *const *
nm_meta_setting_info_valid_parts_for_port_type(const char *port_type, const char **out_port_name);

gboolean nm_meta_property_int_get_range(const NMMetaPropertyInfo *property_info,
                                        NMMetaSignUnsignInt64    *out_min,
                                        NMMetaSignUnsignInt64    *out_max);

gboolean nm_meta_property_enum_get_range(const NMMetaPropertyInfo *property_info,
                                         int                      *out_min,
                                         int                      *out_max);

GType nm_meta_property_enum_get_type(const NMMetaPropertyInfo *property_info);

/*****************************************************************************/

typedef enum {
    NM_META_ENV_WARN_LEVEL_INFO,
    NM_META_ENV_WARN_LEVEL_WARN,
} NMMetaEnvWarnLevel;

typedef enum {
    NM_META_ENV_FLAGS_NONE    = 0,
    NM_META_ENV_FLAGS_OFFLINE = 0x1,
} NMMetaEnvFlags;

/* the settings-meta data is supposed to be independent of an actual client
 * implementation. Hence, there is a need for hooks to the meta-data.
 * The meta-data handlers may call back to the environment with certain
 * actions. */
struct _NMMetaEnvironment {
    void (*warn_fcn)(
        const NMMetaEnvironment *environment,
        gpointer                 environment_user_data,
        NMMetaEnvWarnLevel       warn_level,
        const char *
            fmt_l10n, /* the untranslated format string, but it is marked for translation using N_(). */
        va_list ap);

    struct _NMDevice *const *(*get_nm_devices)(const NMMetaEnvironment *environment,
                                               gpointer                 environment_user_data,
                                               guint                   *out_len);

    struct _NMRemoteConnection *const *(*get_nm_connections)(const NMMetaEnvironment *environment,
                                                             gpointer environment_user_data,
                                                             guint   *out_len);

    NMMetaEnvFlags (*get_env_flags)(const NMMetaEnvironment *environment,
                                    gpointer                 environment_user_data);
};

static inline NMMetaEnvFlags
nm_meta_environment_get_env_flags(const NMMetaEnvironment *environment,
                                  gpointer                 environment_user_data)
{
    if (environment && environment->get_env_flags)
        return environment->get_env_flags(environment, environment_user_data);
    return NM_META_ENV_FLAGS_NONE;
}

/*****************************************************************************/

/* NMSettingBond is special in that it has nested properties.
 * We will add API to proper handle such types (Bond, VPN, User),
 * but for now just expose the type info directly. */

extern const NMMetaType nm_meta_type_nested_property_info;

struct _NMMetaNestedPropertyInfo {
    union {
        const NMMetaType  *meta_type;
        NMMetaPropertyInfo base;
    };
    const NMMetaPropertyInfo *parent_info;
};

struct _NMMetaPropertyTypDataNested {
    const NMMetaNestedPropertyInfo *nested;
    guint                           nested_len;
};

extern const NMMetaPropertyTypDataNested nm_meta_property_typ_data_bond;

/*****************************************************************************/

gboolean _nm_meta_setting_bond_add_option(NMSetting  *setting,
                                          const char *name,
                                          const char *value,
                                          GError    **error);

/*****************************************************************************/

#endif /* __NM_META_SETTING_DESC_H__ */
