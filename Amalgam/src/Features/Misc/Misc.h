#pragma once
#include "../../SDK/SDK.h"

Enum(EBStage, Normal = 0, NormalInverted, Random, RandomInverted);

class CMisc
{
private:
	void AutoJump(CTFPlayer* pLocal, CUserCmd* pCmd);
	void AutoJumpbug(CTFPlayer* pLocal, CUserCmd* pCmd);
	void AutoEdgebug(CTFPlayer* pLocal, CUserCmd* pCmd);
	void AutoStrafe(CTFPlayer* pLocal, CUserCmd* pCmd);
	void MovementLock(CTFPlayer* pLocal, CUserCmd* pCmd);
	void BreakJump(CTFPlayer* pLocal, CUserCmd* pCmd);
	void AntiAFK(CTFPlayer* pLocal, CUserCmd* pCmd);
	void InstantRespawnMVM(CTFPlayer* pLocal);
	void NoisemakerSpam(CTFPlayer* pLocal);

	void CheatsBypass();
	void WeaponSway();

	void TauntKartControl(CTFPlayer* pLocal, CUserCmd* pCmd);
	void FastMovement(CTFPlayer* pLocal, CUserCmd* pCmd);

	void AutoPeek(CTFPlayer* pLocal, CUserCmd* pCmd, bool bPost = false);
	void EdgeJump(CTFPlayer* pLocal, CUserCmd* pCmd, bool bPost = false);

	int m_iEdgeBugTicksLeft = 0;
	int m_iEdgeBugTicksTotal = 0;
	int m_iEdgeBugTicksUntilLand = 0;
	int m_iEdgeBugMoveStage = EBStageEnum::Normal;
	float m_flEdgeBugYawDelta = 0.f;
	float m_flEdgeBugStartYaw = 0.f;
	Vector2D m_vEdgeBugMove = {};
	bool m_bEdgeBugCrouch = false;
	bool m_bEdgeBugRepredict = false;
	bool m_bEdgeBug = false;
	std::vector<Vec3> m_vEdgebugPath;

	bool m_bPeekPlaced = false;
	Vec3 m_vPeekReturnPos = {};

	// Disguise helpers
	void TryAutoDisguise(CTFPlayer* pLocal);
	void DisguiseAsConfiguredClass(CTFPlayer* pLocal);
	bool IsSpyWithKnife(CTFPlayer* pLocal);
	bool IsDisguised(CTFPlayer* pLocal);

	//bool bSteamCleared = false;

public:
	void RunPre(CTFPlayer* pLocal, CUserCmd* pCmd);
	void RunPost(CTFPlayer* pLocal, CUserCmd* pCmd);

	void Event(IGameEvent* pEvent, uint32_t uNameHash);
	int AntiBackstab(CTFPlayer* pLocal, CUserCmd* pCmd, bool bSendPacket);
	void AutoFaNJump(CTFPlayer* pLocal, CTFWeaponBase* pWeapon, CUserCmd* pCmd);

	void PingReducer();
	void UnlockAchievements();
	void LockAchievements();

	int m_iWishCmdrate = -1;
	int m_iWishUpdaterate = -1;
};

ADD_FEATURE(CMisc, Misc);