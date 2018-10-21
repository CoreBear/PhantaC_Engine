#ifndef _GLOBAL_STRUCTURES_H
#define _GLOBAL_STRUCTURES_H

enum   CONSTANT_BUFFER_TYPE	{ APPLICATION = 0, FRAME, OBJECT, COUNT };

struct DEPTH_STENCIL_STATE	{ enum { DEFAULT = 0, COUNT }; };
struct DEPTH_STENCIL_VIEW	{ enum { DEFAULT = 0, COUNT }; };
struct INPUT_LAYOUT			{ enum { DEFAULT = 0, COUNT }; };
struct PIXEL_SHADER			{ enum { DEFAULT = 0, COUNT }; };
struct RASTERIZER_STATE		{ enum { DEFAULT = 0, COUNT }; };
struct RENDER_TARGET_VIEW	{ enum { DEFAULT = 0, COUNT }; };
struct TEXTURE2D			{ enum { DEFAULT = 0, COUNT }; };
struct VERTEX_BUFFER		{ enum { DEFAULT = 0, COUNT }; };
struct VERTEX_SHADER		{ enum { DEFAULT = 0, COUNT }; };
struct VIEWPORT				{ enum { DEFAULT = 0, COUNT }; };

#endif
