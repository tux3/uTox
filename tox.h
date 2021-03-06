/* todo: proper system for posting messages to the toxcore thread, comments, better names (?), proper cleanup of a/v and a/v thread*/
/* -proper unpause/pause file transfers, resuming file transfers + what if new file transfer with same id gets created before the main thread receives the message for the old one?
>= GiB file sizes with FILE_*_PROGRESS on 32bit */

/* details about messages and their (param1, param2, data) values are in the message handlers in tox.c*/

/* toxcore thread messages (send from the client thread)
 */
enum {
    TOX_KILL,

    TOX_SETNAME,
    TOX_SETSTATUSMSG,
    TOX_SETSTATUS,
    TOX_ADDFRIEND,
    TOX_DELFRIEND,
    TOX_ACCEPTFRIEND,
    TOX_SENDMESSAGE,
    TOX_SENDMESSAGEGROUP,
    TOX_CALL,
    TOX_ACCEPTCALL,
    TOX_HANGUP,
    TOX_NEWGROUP,
    TOX_LEAVEGROUP,
    TOX_GROUPINVITE,

    TOX_SENDFILES,
    TOX_ACCEPTFILE,
    TOX_FILE_IN_CANCEL,
    TOX_FILE_OUT_CANCEL,
    TOX_FILE_IN_PAUSE,
    TOX_FILE_OUT_PAUSE,
    TOX_FILE_IN_RESUME,
    TOX_FILE_OUT_RESUME,
};

/* client thread messages (recieved by the client thread)
 */
enum {
    /* general messages */
    TOX_DONE,
    DHT_CONNECTED,
    DNS_RESULT,

    /* friend related */
    FRIEND_REQUEST,
    FRIEND_ACCEPT,
    FRIEND_ADD,
    FRIEND_MESSAGE,
    FRIEND_NAME,
    FRIEND_STATUS_MESSAGE,
    FRIEND_STATUS,
    FRIEND_TYPING,
    FRIEND_ONLINE,

    /* friend a/v */
    FRIEND_CALL_INVITE,
    FRIEND_CALL_START,
    FRIEND_CALL_RING,
    FRIEND_CALL_END,

    /* friend file */
    FRIEND_FILE_IN_NEW,
    FRIEND_FILE_OUT_NEW,
    FRIEND_FILE_IN_STATUS,
    FRIEND_FILE_OUT_STATUS,
    FRIEND_FILE_IN_PROGRESS,
    FRIEND_FILE_OUT_PROGRESS,

    /* group */
    GROUP_ADD,
    GROUP_MESSAGE,
    GROUP_PEER_ADD,
    GROUP_PEER_DEL,
    GROUP_PEER_NAME,
};

/* toxcore thread
 */
void tox_thread(void *args);

/* send a message to the toxcore thread
 */
void tox_postmessage(uint8_t msg, uint16_t param1, uint16_t param2, void *data);

/* read a message sent from the toxcore thread (sent with postmessage())
 */
void tox_message(uint8_t msg, uint16_t param1, uint16_t param2, void *data);
