# miniRT

┌─────────────────────────────────────────────────────────────────┐
│                         PROGRAM START                            │
└─────────────────────────────────────────────────────────────────┘
                              ↓
┌─────────────────────────────────────────────────────────────────┐
│  1. PARSE SCENE FILE                                            │
│     • Read .rt file                                             │
│     • Parse entities (A, C, L, sp, pl, cy)                      │
│     • Validate syntax and values                                │
│     • Build world data structure                                │
└─────────────────────────────────────────────────────────────────┘
                              ↓
┌─────────────────────────────────────────────────────────────────┐
│  2. SETUP VIEWPORT                                              │
│     • Calculate viewport dimensions (FOV)                       │
│     • Build camera coordinate system                            │
│     • Compute right, up, forward vectors                        │
└─────────────────────────────────────────────────────────────────┘
                              ↓
┌─────────────────────────────────────────────────────────────────┐
│  3. INITIALIZE GRAPHICS                                         │
│     • Create MLX window (WIDTH × HEIGHT)                        │
│     • Allocate image buffer                                     │
│     • Setup event handlers (keyboard)                           │
└─────────────────────────────────────────────────────────────────┘
                              ↓
┌─────────────────────────────────────────────────────────────────┐
│  4. RENDER LOOP (for each pixel)                                │
└─────────────────────────────────────────────────────────────────┘
                              ↓
        ┌─────────────────────────────────────────────────┐
        │  	 For y = 0 to HEIGHT                          │
        │    For x = 0 to WIDTH                           │
        └─────────────────────────────────────────────────┘
                              ↓
        ┌─────────────────────────────────────────────────┐
        │  4a. GENERATE RAY                               │
        │      • Convert pixel (x,y) to viewport [-1,1]   │
        │      • Scale by viewport dimensions             │
        │      • Apply camera basis vectors               │
        │      • Normalize ray direction                  │
        └─────────────────────────────────────────────────┘
                              ↓
        ┌─────────────────────────────────────────────────┐
        │  4b. INTERSECTION TEST                          │
        │      • Test ray against all shapes              │
        │      • Keep closest hit (smallest t > 0)        │
        │      • Store: t, point, shape, color            │
        └─────────────────────────────────────────────────┘
                              ↓
        ┌─────────────────────────────────────────────────┐
        │  4c. COMPUTE NORMAL                             │
        │      • Sphere: (point - center)                 │
        │      • Plane: plane.normal                      │
        │      • Cylinder: perpendicular to axis/caps     │
        │      • Normalize result                         │
        └─────────────────────────────────────────────────┘
                              ↓
        ┌─────────────────────────────────────────────────┐
        │  4d. LIGHTING CALCULATION                       │
        │      ┌────────────────────────────────┐         │
        │      │  Ambient Component             │         │
        │      │  color × ambient_ratio         │         │
        │      └────────────────────────────────┘         │
        │                    ↓                            │
        │      ┌────────────────────────────────┐         │
        │      │  Shadow Test                   │         │
        │      │  • Cast ray to light           │         │
        │      │  • Check for occlusion         │         │
        │      └────────────────────────────────┘         │
        │                    ↓                            │
        │      ┌────────────────────────────────┐         │
        │      │  If NOT in shadow:             │         │
        │      │  Diffuse Component             │         │
        │      │  • cos(angle) × attenuation    │         │
        │      │  • color × light_intensity     │         │
        │      └────────────────────────────────┘         │
        │                    ↓                            │
        │      ┌────────────────────────────────┐         │
        │      │  Final Color                   │         │
        │      │  ambient + diffuse             │         │
        │      └────────────────────────────────┘         │
        └─────────────────────────────────────────────────┘
                              ↓
        ┌─────────────────────────────────────────────────┐
        │  4e. WRITE PIXEL                                │
        │      • Clamp RGB to [0, 255]                    │
        │      • Write to image buffer                    │
        └─────────────────────────────────────────────────┘
                              ↓
                      (next pixel)
                              ↓
┌─────────────────────────────────────────────────────────────────┐
│  5. DISPLAY IMAGE                                               │
│     • Copy buffer to window                                     │
│     • Present to screen                                         │
└─────────────────────────────────────────────────────────────────┘
                              ↓
┌─────────────────────────────────────────────────────────────────┐
│  6. EVENT LOOP                                                  │
│     • Wait for user input                                       │
│     • WASD/CV: Move camera → re-render                          │
│     • ESC: Quit program                                         │
└─────────────────────────────────────────────────────────────────┘
