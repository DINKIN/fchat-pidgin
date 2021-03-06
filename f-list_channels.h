/*
 * F-List Pidgin - a libpurple protocol plugin for F-Chat
 *
 * Copyright 2011 F-List Pidgin developers.
 *
 * This file is part of F-List Pidgin.
 *
 * F-List Pidgin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * F-List Pidgin is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with F-List Pidgin.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef FLIST_CHANNELS_H
#define	FLIST_CHANNELS_H

#include "f-list.h"

typedef struct FListChannel_ FListChannel;

struct FListChannel_ {
    gchar *name;
    gchar *title;
    GHashTable *users;
    gchar *owner;
    GList *operators;
    FListChannelMode mode;
    gchar *topic;
};

FListFlags flist_get_flags(FListAccount *, const gchar *channel, const gchar *identity);

void flist_channel_print_error(PurpleConversation *convo, const gchar *message);
void flist_channel_print_op_warning(PurpleConversation *convo, const gchar *character, const gchar *message);

void flist_update_user_chats_offline(FListAccount *, const gchar *);
void flist_update_user_chats_rank(FListAccount *, const gchar *);
void flist_update_users_chats_rank(FListAccount *, GList *);

void flist_got_channel_topic(FListAccount *, const gchar *channel, const gchar *topic);
void flist_got_channel_mode(FListAccount *, const gchar *channel, const gchar *mode);
void flist_got_channel_joined(FListAccount *, const gchar *);
void flist_got_channel_left(FListAccount *, const gchar *);
void flist_got_channel_oplist(FListAccount *, const gchar *channel, GList *oplist);
void flist_got_channel_userlist(FListAccount *, const gchar *channel, GList *users);
void flist_got_channel_user_joined(FListAccount *, const gchar *, const gchar *);
void flist_got_channel_user_left(FListAccount *, const gchar *, const gchar *, const gchar *);

FListChannel *flist_channel_find(FListAccount *, const gchar *channel);
FListChannel *flist_channel_new(FListAccount *, const gchar *channel);
const gchar *flist_channel_get_title(FListChannel *);
GList *flist_channel_list_names(FListAccount *);
GList *flist_channel_list_all(FListAccount *);
void flist_channel_display_topic_ui(PurpleConversation *convo, const gchar *current_topic);
void flist_show_channel_mode(FListAccount *fla, const gchar *channel);

void flist_channel_subsystem_load(FListAccount*);
void flist_channel_subsystem_unload(FListAccount*);
char *flist_get_channel_name(GHashTable *components);

PurpleCmdRet flist_channel_code_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_oplist_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_op_deop_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_join_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_banlist_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_who_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_open_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_close_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_get_mode_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_set_mode_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_show_topic_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_show_raw_topic_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_set_topic_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_set_owner_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_get_owner_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_kick_ban_unban_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_invite_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_make_cmd(PurpleConversation *, const gchar *, gchar **args, gchar **error, void *);
PurpleCmdRet flist_channel_timeout_cmd(PurpleConversation *convo, const gchar *cmd, gchar **args, gchar **error, void *data);

gboolean flist_process_COL(FListAccount *, JsonObject *);
gboolean flist_process_JCH(FListAccount *, JsonObject *);
gboolean flist_process_LCH(FListAccount *, JsonObject *);
gboolean flist_process_ICH(FListAccount *, JsonObject *);
gboolean flist_process_CKU(FListAccount *, JsonObject *);
gboolean flist_process_CBU(FListAccount *, JsonObject *);
gboolean flist_process_CTU(FListAccount *, JsonObject *);
gboolean flist_process_CDS(FListAccount *, JsonObject *);
gboolean flist_process_RMO(FListAccount *, JsonObject *);
gboolean flist_process_CIU(FListAccount *, JsonObject *);

#endif	/* F_LIST_CHANNELS_H */

