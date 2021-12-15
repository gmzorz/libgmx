/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   xevent.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 17:04:42 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/15 13:30:14 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H
# define EXIT_WINDOW	17
# define MASK_BUTTON	0L
# define KEY_DOWN		2
# define KEY_UP			3
# define MOUSE_DOWN		4
# define MOUSE_UP		5
# define MOTION			6

typedef enum e_mouseflag
{
	MOUSE_HIDE		= 0x000,
	MOUSE_SHOW		= 0x001,
	MOUSE_LOCK		= 0x100,
	MOUSE_FREE		= 0x200
}	t_mouseflag;

typedef enum e_xevent
{
	KEYBOARD_KEYPRESS 			= 0x02,
	KEYBOARD_KEYRELEASE 		= 0x03,
	KEYBOARD_KEYMAPNOTIFY 		= 0x0B,
	MOUSE_BUTTONPRESS 			= 0x04,
	MOUSE_BUTTONRELEASE 		= 0x05,
	MOUSE_MOTIONNOTIFY 			= 0x06,
	WINDOW_ENTERNOTIFY 			= 0x07,
	WINDOW_LEAVENOTIFY 			= 0x08,
	WINDOW_FOCUSIN 				= 0x09,
	WINDOW_FOCUSOUT 			= 0x0A,
	WINDOW_EXPOSE 				= 0x0C,
	WINDOW_GRAPHICSEXPOSE 		= 0x0D,
	WINDOW_NOEXPOSE 			= 0x0E,
	WINDOW_VISIBILITYNOTIFY 	= 0x0F,
	WINDOW_CREATENOTIFY 		= 0x10,
	WINDOW_DESTROYNOTIFY 		= 0x11,
	WINDOW_UNMAPNOTIFY 			= 0x12,
	WINDOW_MAPNOTIFY 			= 0x13,
	WINDOW_MAPREQUEST 			= 0x14,
	WINDOW_REPARENTNOTIFY 		= 0x15,
	WINDOW_CONFIGURENOTIFY 		= 0x16,
	WINDOW_CONFIGUREREQUEST 	= 0x17,
	WINDOW_GRAVITYNOTIFY 		= 0x18,
	WINDOW_RESIZEREQUEST 		= 0x19,
	WINDOW_CIRCULATENOTIFY 		= 0x1A,
	WINDOW_CIRCULATEREQUEST 	= 0x1B,
	WINDOW_PROPERTYNOTIFY 		= 0x1C,
	CLIENT_SELECTIONCLEAR 		= 0x1D,
	CLIENT_SELECTIONREQUEST 	= 0x1E,
	CLIENT_SELECTIONNOTIFY 		= 0x1F,
	CLIENT_COLORMAPNOTIFY 		= 0x20,
	CLIENT_CLIENTMESSAGE 		= 0x21,
	CLIENT_MAPPINGNOTIFY 		= 0x22
}	t_xevent;

typedef enum e_mousebutton
{
	MOUSE1		= 0x1,
	MOUSE2		= 0x2,
	MOUSE3		= 0x3,
	MOUSE4		= 0x4,
	MOUSE5		= 0x5,
	MOUSE_NONE	= 0xFFFFFFFF
}	t_mousebutton;

typedef struct s_mouse_selector
{
	t_mousebutton			button;
	void					(*press)(int32_t x, int32_t y);
	struct s_mouse_selector	*next;
}	t_mouse_selector;

typedef enum e_keybutton
{
	VK_ESC		= 0x035,
	VK_Q		= 0x00C,
	VK_W		= 0x00D,
	VK_E		= 0x00E,
	VK_R		= 0x00F,
	VK_T		= 0x011,
	VK_Y		= 0x010,
	VK_U		= 0x020,
	VK_I		= 0x022,
	VK_O		= 0x01F,
	VK_A		= 0x000,
	VK_S		= 0x001,
	VK_D		= 0x002,
	VK_J		= 0x026,
	VK_K		= 0x028,
	VK_L		= 0x025,
	VK_Z		= 0x006,
	VK_X		= 0x007,
	VK_ENTER	= 0x024,
	VK_ONE		= 0x012,
	VK_TWO		= 0x013,
	VK_THREE	= 0x014,
	VK_FOUR		= 0x015,
	VK_FIVE		= 0x017,
	VK_SIX		= 0x016,
	VK_SEVEN	= 0x01A,
	VK_COMMA	= 0x02B,
	VK_DOT		= 0x02F,
	VK_SPACE	= 0x031,
	VK_PLUS		= 0x018,
	VK_MINUS	= 0x01B,
	VK_SHIFT	= 0x101,
	VK_UP		= 0x07D,
	VK_DOWN		= 0x07E,
	VK_NOKEY	= 0xFFFFFFFF
}	t_keybutton;

#endif
