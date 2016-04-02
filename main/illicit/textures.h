#ifndef __TEXTURES_H
#define __TEXTURES_H


/*
Original Source: http://www.tusticles.com/scripts/gta



// before '=' : dict name
// after '=' : sprite names

1 : frontend = gradient_background , gtav_logo , newsaving , spinner
2 : 3dtextures = mpgroundlogo_bikers , mpgroundlogo_cops , mpgroundlogo_vagos
3 : assassinations = target1 , target 3 , targeta , targetb , targetquestion
4 : awards = missionscore
5 : basejumping = arrow_pointer
6 : commonmenu = arrowleft , arrowright , bettingbox_centre , bettingbox_left , bettingbox_right , common_medal , gradient_bgd , gradient_nav , header_gradient_script , interaction_bgd , 
medal_bronze , medal_gold , medal_silver , mp_alerttriangle , mp_hostcrown , mp_medal_bronze , mp_medal_gold , mp_medal_silver , mp_specitem_cash , mp_specitem_coke , mp_specitem_heroin , mp_specitem_meth , mp_specitem_weed , shop_ammo_icon_a , shop_ammo_icon_b , shop_armour_icon_a , shop_armour_icon_b , shop_arrows_upanddown , shop_barber_icon_a , shop_barber_icon_b , shop_box_blank , shop_box_blankb , shop_box_cross , shop_box_crossb , shop_box_tick , shop_box_tickb , shop_clothing_icon_a , shop_clothing_icon_b , shop_franklin_icon_a , shop_franklin_icon_b , shop_garage_bike_icon_a , shop_garage_bike_icon_b , shop_garage_icon_a , shop_garage_icon_b , shop_gunclub_icon_a , shop_gunclub_icon_b , shop_health_icon_a , shop_health_icon_b , shop_lock , shop_makeup_icon_a , shop_makeup_icon_b , shop_mask_icon_a , shop_mask_icon_b , shop_michael_icon_a , shop_michael_icon_b , shop_new_star , shop_tattoos_icon_a , shop_tattoos_icon_b , shop_tick_icon , shop_trevor_icon_a , shop_trevor_icon_b
7 : commonmenutu = arrowleft , arrowright , base_jumping , capture_the_flag , custom_mission , deathmatch , gang_attack , last_team_standing , race , race_air , 
race_bicycle , race_foot , race_land , race_water , rockstar , survival , team_deathmatch , vehicle_deathmatch
8 : cross = circle_checkpoints_cross
9 : dancingmg = dance , great , leveld , levelu , missed , perfect , ready , weak
10 : darts = dart_reticules , dart_reticules_zoomed , xj_v_blackboard01
11 : digitaloverlay = nscanline1 , nscuzz1 , nscuzz2 , nscuzz3 , signal1 , signal2 , signal3 , signal4 , static1 , static2 , static3 , static4 , static5
12 : fbi1 : zipbig
13 : golfputting = puttingmarker
14 : heisthud = hc_franklin , hc_lester , hc_micheal , hc_n_che , hc_n_chr , hc_n_dar , hc_n_edd , hc_n_gus , hc_n_hug , hc_n_kar , hc_n_nor , hc_n_pac , hc_n_pai , hc_n_ric , hc_n_tal , hc_trevor , kiaoverlay , main_gradient
15 : helicopterhud = hudarrow , hud_block , hud_corner , hud_dest , hud_horiz , hud_line , hud_lock , hud_outline , hud_outline_thin , hud_target , hud_vert , targetlost
16 : hunting = huntingwindarrow_32 , hunting_bronze_128 , hunting_gold_128 , hunting_silver_128
17 : mparrow = mp_arrowlarge , mp_arrowxlarge
18 : mpawardheists = asshole , beprepared , calmdown , canttouchthis , captured , deathdefying , decorated , dressedtoimpress , fairplay , forhire , gimmethat , incontrol , ittakestwo , jackofalltrades , lightsout , livealittle , movingday , noyoudont , oneandonly , onemanarmy , pscychokiller , shotcaller , showroom , stillstanding , thebigtime , thepostman
19 : mpawards1 = armwrestlingvictories , blowupenemiesusingcarbombs , gethaircuts , hangingoutincars , killedpeoplewithamachinegune , killedpeoplewithanassaultrifle , parachute1min , winatdarts
20 : mpawards2 = blowupvehicles , buyeverygun , delivercars , raceswon_generic , securityvansrobbed , timeinheli , timesavoiding5stars
21 : mpawards3 = killenemiesindriveby
22 : mpawards4 = getlapdances , headshots , holdupshops , jackvehicles , killsmg , killstickybombs , noclaimsbonus , spinderella , swallow , thefugitive , unirider
23 : mpawards5 = 10killstreakdeathmatch , birdie , bountyhunter , clearallganghideouts , collectedcrates , comefrombehind , coveredtargetswin , deathmatchcreator , deathmatchwin , earncashfrombetting , fastestlap , fullymodacar , getatattoooneachbodypart , getrevengekilldeathmatch , golfwin , gtaraceswon , hattrickkiller , holdaraceworldrecord , holeinone , jump40m , kill3inaraceandwin , killgrenades , killmeleeweapons , killpistol , killrocketlauncher , killshotgun , killsniperrifle , killstreak , land2mfromtarget , missionscore , mostkillsingangattack , mostkillsinsurvival , overallkills , parachutejumps20m , pickupcratefirst , play25differentdeathmatches , play25differentraces , playedcreation , racecreator , racetopointwinner , randomtargetswin , reachhordemodewave , shootdownpoliceheli , sixdartcheckout , stolenkill , targetgridgranny , targetgridwin , teamdeathmatchmvp , teamdeathmatchwin , tennisfivesets , tennismatcheswon , tennisserviceace , tennisstraightsets , totalkills , 
wear25differentitemsofclothing , winacustomclassrace , winaplanerace , winasearace , wineverygamemodeonce , wineverytypeofrace , winrallyasdriver , winrallyasnavigator
24 : mpawards6 = autogo , creatorsscore , dailyduty , flybye , goaloriented , joyrider , overachiever , overhere
25 : mpcarhud = albany , annis , banshee , benefactor , bf , bollokan , bravado , brute , buckingham , canis , 
chariot , cheval , city , classique , coil , country_side , declasse , dewbauchee , dilettante , dinka , dundreary , 
emporer , enus , fathom , galivanter , grotti , hijak , hvy , imponte , invetero , jacksheepe , jobuilt , 
karin , lampadati , leaderboard_car_colour_icon , leaderboard_car_colour_icon_2ndaryhalf.d , leaderboard_car_colour_icon_primaryhalf. , leaderboard_car_colour_icon_singlecolour , maibatsu , mammoth , mp_rankbarfill , mtl , nagasaki , obey , ocelot , overflod , ped , pegassi , pfister , principe , progen , schyster , shitzu , speedophile , stanley , transport_bicycle_icon , transport_bike_icon , transport_boat_icon , transport_car_icon , transport_heli_icon , transport_plane_icon , tricycles , truffade , ubermacht , vapid , vehicle_card_icons_acceleration , vehicle_card_icons_braking , vehicle_card_icons_flag_default , vehicle_card_icons_flag_france , vehicle_card_icons_flag_germany , vehicle_card_icons_flag_italy , vehicle_card_icons_flag_japan , vehicle_card_icons_flag_korea , vehicle_card_icons_flag_sweden , vehicle_card_icons_flag_uk , vehicle_card_icons_flag_usa , vehicle_card_icons_handling , vehicle_card_icons_speed , vehicle_card_icons_winratio , vulcar , weeny , western , westernmotorcycle , willard , zirconium
26 : mpcarhud2 = grotti_2 , lcc , progen
27 : mpcharselect = mp_generic_avatar
28 : mpdebugmap = debugmap
29 : mpentry = birdsandbees_flat , mp_main_gradient , mp_modenotselected_gradient , mp_modeselected_gradient
30 : mphud = ammo_pickup , light , machine1 , machine3 , machine5 , machine6 , missionpassedbox , missionpassedgradien , missionpassedmedal , mp_anim_ammo , mp_anim_cash , mp_anim_rp , mp_crew_icon_default , mp_no_crew , mp_player_betting , mp_player_ready , mp_player_spanner , r_north , r_ny , r_tartan , spectating , thumb_down , thumb_down_gradient , thumb_down_white , thumb_up , thumb_up_gradient , thumb_up_white
31 : mpinteraction = menubar
32 : mpinventory = arm_wrestling , basejump , custom_mission , darts , deathmatch , drug_trafficking , gang_attack , golf , inworld_ringpointer , inworld_ringpointer_blue , in_world_circle , mp_arrow , mp_specitem_bike , mp_specitem_bike_black , mp_specitem_black , mp_specitem_boat , mp_specitem_boatpickup , mp_specitem_boatpickup_black , mp_specitem_boat_black , mp_specitem_car , mp_specitem_car_black , mp_specitem_cash , mp_specitem_cash_black , mp_specitem_coke , mp_specitem_coke_black , mp_specitem_cuffkeys , mp_specitem_cuffkeys_black , mp_specitem_data , mp_specitem_heli , mp_specitem_heli_black , mp_specitem_heroin , mp_specitem_heroin_black , mp_specitem_keycard , mp_specitem_keycard_black , mp_specitem_meth , mp_specitem_meth_black , mp_specitem_package , mp_specitem_package_black , mp_specitem_partnericon , mp_specitem_ped , mp_specitem_ped_black , mp_specitem_plane , mp_specitem_plane2 , mp_specitem_plane_black , mp_specitem_randomobject , mp_specitem_randomobject_black , mp_specitem_remote , mp_specitem_remote_black , mp_specitem_safe , mp_specitem_steer_wheel , mp_specitem_weapons , mp_specitem_weapons_black , mp_specitem_weed , mp_specitem_weed_black , race_air , race_bike , race_boat , race_foot , race_land , race_offroad , shooting_range , survival , team_deathmatch , tennis , vehicle_deathmatch
33 : mpleaderboard = gradient_template , leaderboard_audio_1 , leaderboard_audio_2 , leaderboard_audio_3 , leaderboard_audio_inactive , leaderboard_audio_mute , leaderboard_betting_icon , leaderboard_bikers_icon , leaderboard_car_colour_bg , leaderboard_car_colour_icon , leaderboard_car_icon , leaderboard_cash_icon , leaderboard_cops_icon , leaderboard_cup_icon , leaderboard_deaths_icon , leaderboard_female_icon , leaderboard_freemoderank_icon , leaderboard_friends_icon , leaderboard_globe_icon , leaderboard_kd_icon , leaderboard_kick_icon , leaderboard_kills_icon , leaderboard_lap_icon , leaderboard_loss_icon , leaderboard_male_icon , leaderboard_minus_icon , leaderboard_parachute_colour_icon , leaderboard_players_icon , leaderboard_plus_icon , leaderboard_points_icon , leaderboard_position_icon , leaderboard_rankshield_icon , leaderboard_ratio_icon , leaderboard_socialclub_icon , leaderboard_star_icon , leaderboard_steeringwheel_icon , leaderboard_thumb , leaderboard_time_icon , leaderboard_transport_bicycle_icon , leaderboard_transport_bike_icon , leaderboard_transport_boat_icon , leaderboard_transport_car_icon , leaderboard_transport_heli_icon , 
leaderboard_transport_plane_icon , leaderboard_voteblank_icon , leaderboard_votecross_icon , leaderboard_votetick_icon , leaderboard_xp_icon
34 : mplobby = mparrowsmall , mp_charcard_stats_icons7 , mp_charcard_stats_icons8 , mp_charcard_stats_icons9 , mp_charcard_stats_icons10 , mp_minimap1
35 : mpmedals_feed = feed_medal_flightschool , feed_medal_shootingrange , feed_medal_triathlon
36 : mpmissionend = bronzemedal , emptytickbox , goldmedal , silvermedal , tickedtickbox
37 : mpmissmarkers128 = air_race_icon , arm_wrestling_icon , basejump_icon , bike_race_icon , corona_marker , corona_point , corona_shade , custom_icon , darts , deathmatch_marker_128 , foot_race_icon , gangattack_icon , golf_icon , land_race_icon , off_road_race_icon , sea_race_icon , shooting_range_icon , survival_icon , teamdeathmatch_icon , tennis_icon , vehicledeathmatch_icon
38 : mpmissmarkers256  = air_race_icon , arm_wrestling_icon , basejump_icon , bike_race_icon , capture_the_flag_icon , corona_marker , corona_point , corona_shade , custom_icon , darts_icon , 
deathmatch_marker_256 , foot_race_icon , gangattack_icon , golf_icon , land_race_icon , last_team_standing_icon , off_road_race_icon , pilot_school_icon , sea_race_icon , shooting_range_icon , survival_icon , 
teamdeathmatch_icon , tennis_icon , vehicledeathmatch_icon
39 : mponmissmarkers = capture_the_flag_base_icon
40 : mpoverview = mp_rankbarfill , mp_rankbarfill_full , mp_rankbarsstrokethick , mp_rankbarsstrokethin
41 : mprankbadge = globe , globe_bg , rankglobe_21x21_colour
42 : mprpsymbol = rp
43 : mpsafecracking = dail , dail_bg , lock_closed , lock_closed_dark , lock_open , lock_open_dark
44 : mpshops = shopui_title_graphics_sale
45 : mpsrange = panelback , weap_ar_5 , weap_ar_6 , weap_hg_5 , weap_hg_6 , weap_hg_7 , weap_lmg_4
46 : mptattoos = armoredvantakedowns , clearout , getrevengekills , holdwoldrecord , kill3others , killplayerbountyhead , reachrank1 , reachrank2 , reachrank3 , thehustler , theslayer , wineverymodeonce
47 : mptattoos1 = tattoo_policestbust , tattoo_avoid_arrest , tattoo_defend_safehouse , tattoo_drugdeal , tattoo_escort_crookboss , tattoo_every_upgrade_vagos_car , tattoo_funeral_defending , tattoo_no_kill_all_gang
48 : mptattoos2 = tattoo_hold_up_shops_10 , tattoo_hold_up_shops_25 , tattoo_hold_up_shops_50 , tattoo_hold_up_shops_100 , tattoo_kill_a_snitch , tattoo_kill_gang_memberr_10 , tattoo_kill_gang_memberr_500 , tattoo_kill_rival 
49 : mptattoos3 = mp_fm_tat_002 , mp_fm_tat_019 , mp_fm_tat_023 , mp_fm_tat_036 , mp_fm_tat_037 , mp_fm_tat_039 , mp_fm_tat_040 , mp_fm_tat_award_008 , mp_fm_tat_award_014 , tattoo_pass_boss_meet , tattoo_pass_prisonbreak , tattoo_races_won , tattoo_reach_rank_r_10 , tattoo_reach_rank_r_25 , tattoo_reach_rank_r_50 , tattoo_reach_rank_r_100 , tattoo_uncuff_gang_member , tattoo_win_parley
50 : mptattoostshirts_feed = feed_tattoo_01 , feed_tattoo_02 , feed_tattoo_03 , feed_tattoo_04 , feed_tattoo_05 , feed_tattoo_06 , feed_tattoo_07 , feed_tattoo_08 , feed_tattoo_09 , feed_tattoo_10 , feed_tattoo_11 , feed_tattoo_12 , feed_tattoo_13 , feed_tattoo_14 , feed_tattoo_15 , feed_tattoo_16 , feed_tattoo_17 , feed_tattoo_18 , feed_tattoo_19 , feed_tattoo_20 , feed_tattoo_21 , feed_tattoo_22 , feed_tattoo_23 , feed_tattoo_24 , feed_tattoo_25 , feed_tattoo_26 , feed_tattoo_27 , feed_tshirt_01 , feed_tshirt_02 , feed_tshirt_03
51 : mptshirtawardlts = elitas_tshirt
52 : mptshirtawards = pickupcratefirst , reachhordemodewave , rockstarverifiied
53 : mptshirtawards2 = canttouchthis , deathdefying , decorated , forhire , livealittle , onemanarmy , psychokiller , shotcaller , showroom
54 : mptshirtawards3 = feedhiptshirt01 , feedhiptshirt02 , feedhiptshirt03 , feedhiptshirt04 , feedhiptshirt05 , feedhiptshirt06 , feedhiptshirt07 , feedhiptshirt08 , feedhiptshirt09 , feedhiptshirt10 , feedhiptshirt11 , feedhiptshirt12 , feedhiptshirt13 , feedhiptshirt14
55 : mpweaponscommon = w_ex_grenadesmoke , w_ex_grenadesmoke_silhouette , w_ex_pe , w_ex_pe_silhouette , w_lr_rpg , w_lr_rpg_silhouette , w_pi_combatpistol , w_pi_combatpistol_flash , w_pi_combatpistol_flash_silhouette , w_pi_combatpistol_mag1 , w_pi_combatpistol_mag1_silhouette , w_pi_combatpistol_mag2 , w_pi_combatpistol_mag2_silhouette , w_pi_combatpistol_silhouette , w_pi_combatpistol_silhouette_final , w_pi_combatpistol_silhouette_overlay , w_pi_combatpistol_supp , w_pi_combatpistol_supp_silhouette , w_r_grenadelauncher , w_r_grenadelauncher_flash_silhouette , w_r_grenadelauncher_grip , w_r_grenadelauncher_grip_silhouette , w_r_grenadelauncher_laser , w_r_grenadelauncher_scope , w_r_grenadelauncher_scope_silhouette , w_r_grenadelauncher_silhouette , w_r_grenadelauncher_silhouette_overlay , w_sb_microsmg , w_sb_microsmg_flash , w_sb_microsmg_flash_silhouette , w_sb_microsmg_mag1 , w_sb_microsmg_mag1_silhouette , w_sb_microsmg_mag2 , w_sb_microsmg_mag2_silhouette , w_sb_microsmg_scope , w_sb_microsmg_scope_silhouette , w_sb_microsmg_silhouette , w_sb_microsmg_silhouette_overlay , w_sb_microsmg_supp , w_sb_microsmg_supp_silhouette , w_sg_assaultshotgun , w_sg_assaultshotgun_flsh , w_sg_assaultshotgun_flsh_silhouette , w_sg_assaultshotgun_grip , w_sg_assaultshotgun_grip_silhouette , w_sg_assaultshotgun_mag1 , w_sg_assaultshotgun_mag1_silhouette , w_sg_assaultshotgun_mag2 , w_sg_assaultshotgun_mag2_silhouette , w_sg_assaultshotgun_silhouette _overlay , w_sg_assaultshotgun_silhouette , w_sg_assaultshotgun_silhouette_final , w_sg_assaultshotgun_supp , w_sg_assaultshotgun_supp_silhouette , w_sg_pumpshotgun , w_sg_pumpshotgun_flash , w_sg_pumpshotgun_flash_silhouette , w_sg_pumpshotgun_silhouette _overlay , w_sg_pumpshotgun_silhouette , w_sg_pumpshotgun_supp , w_sg_pumpshotgun_supp_silhouette
56 : mpweaponscommon_small = rocket , w_ex_grenadesmoke , w_ex_pe , w_lr_rpg , w_pi_combatpistol , w_r_grenadelauncher , w_sb_assaultsmg , w_sb_microsmg , w_sg_assaultshotgun , w_sg_pumpshotgun
57 : mpweaponsgang0 = w_ar_advancedrifle , w_ar_advancedrifle_flash , w_ar_advancedrifle_flash_silhouette , w_ar_advancedrifle_mag1 , w_ar_advancedrifle_mag1_silhouette , w_ar_advancedrifle_mag2 , w_ar_advancedrifle_mag2_silhouette , w_ar_advancedrifle_scopemedium , w_ar_advancedrifle_scopemedium_silhouette , w_ar_advancedrifle_silhouette , 
w_ar_advancedrifle_silhouette_overlay , w_ar_advancedrifle_supp , w_ar_advancedrifle_supp_silhouette , w_ar_carbinerifle , w_ar_carbinerifle_flash , w_ar_carbinerifle_flash_silhouette , w_ar_carbinerifle_grip , w_ar_carbinerifle_grip_silhouette , w_ar_carbinerifle_mag1 , w_ar_carbinerifle_mag1_silhouette , w_ar_carbinerifle_mag2 , 
w_ar_carbinerifle_mag2_silhouette , w_ar_carbinerifle_railcover , w_ar_carbinerifle_railcover_silhouette , w_ar_carbinerifle_scope , w_ar_carbinerifle_scope_silhouette , w_ar_carbinerifle_silhouette , w_ar_carbinerifle_silhouette_overlay , w_ar_carbinerifle_supp , w_ar_carbinerifle_supp_silhouette , w_ex_grenadefrag , w_ex_grenadefrag_silhouette , w_mg_combatmg , w_mg_combatmg_grip , w_mg_combatmg_grip_silhouette , w_mg_combatmg_mag1 , w_mg_combatmg_mag1_silhouette , w_mg_combatmg_mag2 , w_mg_combatmg_mag2_silhouette , w_mg_combatmg_scope , w_mg_combatmg_scope_silhouette , w_mg_combatmg_silhouette , w_mg_combatmg_silhouette_overlay , 
w_pi_stungun , w_pi_stungun_silhouette , w_sb_smg , w_sb_smg_flash , w_sb_smg_flash_silhouette , w_sb_smg_mag1 , w_sb_smg_mag1_silhouette , w_sb_smg_mag2 , w_sb_smg_mag2_silhouette , w_sb_smg_scope , w_sb_smg_scope_silhouette , 
w_sb_smg_silhouette , w_sb_smg_silhouette_overlay , w_sb_smg_supp , w_sb_smg_supp_silhouette , w_sr_heavysniper , w_sr_heavysniper_scope , w_sr_heavysniper_scope_silhouette , w_sr_heavysniper_scope_small , w_sr_heavysniper_scope_small_silhouette , w_sr_heavysniper_silhouette , w_sr_heavysniper_silhouette_final , 
w_sr_heavysniper_silhouette_overlay , w_sr_sniperrifle , w_sr_sniperrifle_scope , w_sr_sniperrifle_scope_large , w_sr_sniperrifle_scope_large_silhouette , w_sr_sniperrifle_scope_silhouette , w_sr_sniperrifle_silhouette , w_sr_sniperrifle_silhouette_final , w_sr_sniperrifle_silhouette_overlay , w_sr_sniperrifle_supp , w_sr_sniperrifle_supp_silhouette 
58 : mpweaponsgang0_small = w_ar_addvancedrifle , w_ar_carbinerifle , w_ex_grenadefrag , w_mg_combatmg , w_pi_stungun , w_sb_rubber , w_sb_mg , w_sr_heavysniper , w_sr_sniperrifle
59 : mpweaponsgang1 = w_ar_assaultrifle , w_ar_assaultrifle_flash , w_ar_assaultrifle_flash_silhouette , w_ar_assaultrifle_grip , w_ar_assaultrifle_grip_silhouette , w_ar_assaultrifle_mag1 , w_ar_assaultrifle_mag1_silhouette , w_ar_assaultrifle_mag2 , w_ar_assaultrifle_mag2_silhouette , w_ar_assaultrifle_scope , 
w_ar_assaultrifle_scope_silhouette , w_ar_assaultrifle_silhouette , w_ar_assaultrifle_silhouette_overlay , w_ar_assaultrifle_supp , w_ar_assaultrifle_supp_silhouette , w_mg_mg , w_mg_mg_mag1 , w_mg_mg_mag1_silhouette , w_mg_mg_mag2 , w_mg_mg_mag2_silhouette , w_mg_mg_scope , w_mg_mg_scope_silhouette , w_mg_mg_silhouette , w_mg_mg_silhouette_final , w_mg_mg_silhouette_overlay , w_mg_minigun , w_mg_minigun_silhouette , w_pi_apppistol , w_pi_apppistol_flsh , w_pi_apppistol_flsh_silhouette , w_pi_apppistol_mag1 , w_pi_apppistol_mag1_silhouette , w_pi_apppistol_mag2 , w_pi_apppistol_mag2_silhouette , w_pi_apppistol_silhouette , w_pi_apppistol_silhouette_final , w_pi_apppistol_silhouette_overlay , w_pi_apppistol_supp , w_pi_apppistol_supp_silhouette , w_pi_pistol , w_pi_pistol_flash , w_pi_pistol_flash_silhouette , w_pi_pistol_mag1 , w_pi_pistol_mag1_silhouette , w_pi_pistol_mag2 , w_pi_pistol_mag2_silhouette , w_pi_pistol_silhouette , w_pi_pistol_silhouette_final , w_pi_pistol_silhouette_overlay , w_pi_pistol_supp , w_pi_pistol_supp_silhouette , w_sg_sawnoff , w_sg_sawnoff_silhouette
60 : mpweaponsgang1_small = w_ar_assaultrifle , w_mgassaultmg , w_mg_mg , w_mg_minigun , w_pi_apppistol , w_pi_pistol , w_sg_sawnoff
61 : mpweaponsunusedfornow = w_am_digiscanner , w_am_digiscanner_silhouette , w_am_fire_exting , w_am_fire_exting_silhouette , w_am_jerrycan , w_am_jerrycan_silhouette , w_am_loudhailer , w_am_loudhailer_silhouette , w_am_parachute , w_am_parachute_silhouette , w_ex_molotov , w_ex_molotov_silhouette , w_meleelasso_01 , w_meleelasso_silhouette , w_me_bat , w_me_bat_silhouette , w_me_crowbar , w_me_crowbar_silhouette , w_me_fireaxe , w_me_fireaxe_silhouette , w_me_fist , w_me_fist_silhouette , w_me_gclub , w_me_gclub_silhouette , w_me_hammer , w_me_hammer_silhouette , w_me_knife_01 , w_me_knife_silhouette , w_me_nightstick , w_me_nightstick_silhouette , w_me_shovel , w_me_shovel_silhouette , w_me_wrench , w_me_wrench_silhouette
62 : mp_freemode_mc = debugmap , mouse
63 : mugshots = mug01 , mug02 , mug03
64 : pilotschool = empty_128 , flightschool_bronze_128 , flightschool_gold_128 , flightschool_logo_256 , flightschool_silver_128 , hudarrow , locked_icon , medaldot_32 , planeradarover
65 : procreate = boy1s , boy2s , boy3s , dad1s , dad2s , dad3s , girl1s , girl2s , girl3s , mum1s , mum2s , mum3s
66 : ps_menu = common_medal , flightschool_1a_runwaytakeoff , flightschool_1_invert , flightschool_2a_runwaylanding , flightschool_2_knife , flightschool_3_loop , flightschool_4_lowfly , flightschool_5_land , flightschool_6_obstacle , flightschool_7_heliobstacle , flightschool_8_helispeed , flightschool_9_skydive , flightschool_10_skydivemoving , flightschool_11_formation , locked_icon , mp_lock_icon , mp_main_gradient
67 : securitycam = securitycam_box , securitycam_scanlines
68 : shared = bggradient_16x512 , bggradient_32x1024 , crown_32 , emptydot_32 , info_icon_32 , locked_icon_32 , medaldot_32 , medal_bronze_128 , medal_empty_128 , medal_gold_128 , medal_silver_128 , menuarrow_32 , menuplus_32 , newstar_32 , tempscorecard , tempscorecard_256
69 : shopui_title_barber = shopui_title_barber
70 : shopui_title_barber2 = shopui_title_barber2
71 : shopui_title_barber3 = shopui_title_barber3
72 : shopui_title_barber4 = shopui_title_barber4
73 : shopui_title_carmod = shopui_title_carmod
74 : shopui_title_carmod2 = shopui_title_carmod2
75 : shopui_title_conveniencestore = shopui_title_tennisstore , shopui_title_conveniencestore
76 : shopui_title_darts = shopui_title_darts
77 : shopui_title_gasstation = shopui_title_gasstation
78 : shopui_title_golfshop = shopui_title_golfshop
79 : shopui_title_graphics_franklin = shopui_title_graphics_franklin
80 : shopui_title_graphics_micheal = shopui_title_graphics_micheal
81 : shopui_title_graphics_trevor = shopui_title_graphics_trevor
82 : shopui_title_gunclub = shopui_title_gunclub
83 : shopui_title_highendfashion = shopui_title_highendfashion
84 : shopui_title_highendsalon = shopui_title_highendsalon
85 : shopui_title_liqourstore = shopui_title_liqourstore
86 : shopui_title_liqourstore2 = shopui_title_liqourstore2
87 : shopui_title_liqourstore3 = shopui_title_liqourstore3
88 : shopui_title_lowendfashion = shopui_title_lowendfashion
89 : shopui_title_lowendfashion2 = shopui_title_lowendfashion2
90 : shopui_title_midfashion = shopui_title_midfashion
91 : shopui_title_movie_masks = shopui_title_movie_masks
92 : shopui_title_tattoos = shopui_title_tattoos
93 : shopui_title_tattoos2 = shopui_title_tattoos2
94 : shopui_title_tattoos3 = shopui_title_tattoos3
95 : shopui_title_tattoos4 = shopui_title_tattoos4
96 : shopui_title_tattoos5 = shopui_title_tattoos5
97 : shopui_title_tennis = shopui_title_tennis
98 : spcityraces = airport , citycircuit , soutlossantos , terminal , vespuccicanal
99 : splashscreens = gtav_playerintronames_franklin , gtav_playerintronames_michaeld , gtav_playerintronames_michaelt , gtav_playerintronames_trevor
100 : sproffroad = offroad_bronze_128 , offroad_gold_128 , offroad_silver_128 , spr_offroad_1 , spr_offroad_2 , spr_offroad_3 , spr_offroad_4 , spr_offroad_5 , spr_offroad_6
101 : sprraces = empty_128 , flightstunt_bronze_128 , flightstunt_gold_128 , flightstunt_silver_128 , medaldot_32 , mp_lock_icon , spr_desc_1 , spr_desc_2 , spr_desc_3 , spr_desc_4 , spr_desc_5 , spr_desc_desert , spr_desc_lakeloop , spr_desc_sky
102 : spsearaces = canyon , lossantos , northcoast , southcoast 
103 : srange_chal = chal_ar1 , chal_ar2 , chal_ar3 , chal_blank , chal_covered , chal_covered_active , chal_grid , chal_grid_empty , chal_hg1 , chal_hg2 , chal_hg3 , chal_hvy1 , chal_hvy2 , chal_hvy3 , chal_mini_target_64 , chal_random
104 : srange_chal2 = chal_lmg1 , chal_lmg2 , chal_lmg3 , chal_rg1 , chal_rg2 , chal_rg3 , chal_rg4 , chal_sg1 , chal_sg2 , chal_sg3 , chal_smg1 , chal_smg2 , chal_smg3
105 : srange_gen = blanktrophy_bronze , blanktrophy_gold , blanktrophy_silver , empty_128 , hits_dot , hits_target , hit_cross , icon_target_32 , locked_icon , lsgc_logo , medaldot_32 , shooting_bronze_128 , shooting_gold_128 , shooting_silver_128 , unlocked_icon , weapcat_ar , weapcat_ar_2 , weapcat_hg , weapcat_hg_2 , weapcat_hvy , weapcat_lmg , weapcat_lmg_2 , weapcat_sg , weapcat_sg_2 , weapcat_smg , weapcat_smg_2
106 : srange_weap = weap_ar_1 , weap_ar_2 , weap_ar_3 , weap_ar_4 , weap_ar_5 , weap_ar_6 , weap_hg_1 , weap_hg_2 , weap_hg_3 , weap_hg_4 , weap_hg_5 , weap_hg_6 , weap_hg_7 , weap_hvy_1 , weap_rg_1
107 : srange_weap2 = weap_lmg_1 , weap_lmg_2 , weap_lmg_3 , weap_lmg_4 , weap_sg_1 , weap_sg_2 , weap_sg_3 , weap_sg_4 , weap_smg_1 , weap_smg_2 , weap_smg_3 
108 : timerbars = all_black_bg , all_red_bg , all_white_bg , boost , circle_checkpoints , circle_checkpoints_big , circle_checkpoints_outline , damagebarfill_128 , damagebarfill_64 , damagebar_128 , damagebar_64 , lhs_bg , rhs_bg , rockets , spikes
109 : trafficcam = cursor , cursor_lines , lights_h , lights_v , radar_centre , traffic_junction_box , triathlon_junction_line_v , triathlon_lights_horz , triathlon_lights_horz_large , triathlon_lights_vert , triathlon_lights_vert_large , vehicle_marker
110 : triathlon = sprtriathlon_mountainroad_256 , sprtriathlon_musclebeach_256 , sprtriathlon_trailerpark_256 , triathlon_bronze_128 , triathlon_cycling , triathlon_gold_128 , triathlon_running , triathlon_silver_128 , triathlon_swimming
111 : visualflow = crosshair
*/



/*
// textureName

last_team_standing_icon
shop_arrows_upANDdown
tennis_icon
deathmatch_marker_256
MP_hostCrown
MP_SpecItem_Coke
MP_SpecItem_Heroin
MP_SpecItem_Weed
MP_SpecItem_Meth
MP_SpecItem_Cash
survival_icon
shop_NEW_Star
Shop_Tick_Icon
Shop_Box_CrossB
Shop_Box_Cross
Shop_Box_BlankB
Shop_Box_Blank
Shop_Box_TickB
Shop_Box_Tick
basejump_icon
Shop_Clothing_Icon_B
Shop_Clothing_Icon_A
Shop_GunClub_Icon_B
Shop_GunClub_Icon_A
Shop_Ammo_Icon_B
Shop_Ammo_Icon_A
Shop_Armour_Icon_B
Shop_Armour_Icon_A
Shop_Health_Icon_A
Shop_Health_Icon_B
Shop_MakeUp_Icon_B
Shop_MakeUp_Icon_A
Shop_Tattoos_Icon_B
Shop_Tattoos_Icon_A
Shop_Garage_Icon_B
Shop_Garage_Icon_A
Shop_Garage_Bike_Icon_B
Shop_Garage_Bike_Icon_A
Shop_Barber_Icon_B
Shop_Barber_Icon_A
darts_icon
corona_point
shop_Lock
vehicledeathmatch_icon
arrowleft
arrowright
MP_AlertTriangle
gangattack_icon
Shop_Michael_Icon_B
Shop_Michael_Icon_A
Shop_Franklin_Icon_B
Shop_Franklin_Icon_A
Shop_Trevor_Icon_B
Shop_Trevor_Icon_A
sea_race_icon
foot_race_icon

// Streamedtexture

CommonMenu
MPWeaponsCommon
mpmissmarkers256
MPWeaponsGang0
MPWeaponsGang1
*/

/*
void REQUEST_STREAMED_TEXTURE_DICT(char *, bool);
bool HAS_STREAMED_TEXTURE_DICT_LOADED(char *);

void DrawSprite(char * Streamedtexture, char * textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);
	HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture);
	DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a);
}
*/


#endif

