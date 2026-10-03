
#ifdef rumble
#include <kos.h>
#include <dc/maple/purupuru.h>

/// <summary>
void RunDCHandleFF();
static int ff_enable = 1;
static int ff_timeout = 0;
static int ff_frequency = 0;
static int ff_intensity = 0;
static int ff_select = 0x10;

typedef uint64_t uint64;

int I_GetTime(void)
{
	uint64 curr_ms;

	thd_pass();

	curr_ms = timer_ms_gettime64();
	return curr_ms * 2294 >> 16;
}

// Force Feedback
void I_Tactile(int freq, int intensity, int select)
{
	ff_frequency = freq;
	ff_intensity = intensity;
	ff_select = select;
	ff_timeout = I_GetTime() + 35;

	// FF will be handled at the same time as the events
}

static void dc_handle_ff(void) //
{
	maple_device_t* jump;

	if (!ff_enable)
		return; // early out

	jump = maple_enum_type(0, MAPLE_FUNC_PURUPURU);

	if (ff_timeout && jump)
	{
		if (I_GetTime() >= ff_timeout)
		{
			static purupuru_effect_t effect;
			effect.duration = 0x00;
			effect.effect2 = 0x00;
			effect.effect1 = 0x00;
			effect.special = PURUPURU_SPECIAL_MOTOR1;
			purupuru_rumble(jump, &effect);
			ff_timeout = 0;
			ff_intensity = 0;
		}
	}

	if (ff_intensity && jump)
	{
		static purupuru_effect_t effect;
		effect.duration = 0x11;
		effect.effect2 = ff_frequency;
		effect.effect1 = PURUPURU_EFFECT1_INTENSITY(ff_intensity);
		effect.special = PURUPURU_SPECIAL_MOTOR1 | ff_select;
		purupuru_rumble(jump, &effect);
		ff_intensity = 0;
	}
}

void RunDCHandleFF()
{
	dc_handle_ff();
}

/// </summary>
#endif
