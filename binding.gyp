{
  'variables': {
    'platform': '<(OS)',
  },
  'conditions': [
    # Replace gyp platform with node platform, blech
    ['platform == "mac"', {'variables': {'platform': 'darwin'}}],
    ['platform == "win"', {'variables': {'platform': 'win32'}}],
  ],
  'targets': [
    {
      'target_name': 'openvr',
      'defines': [
        'VERSION=0.4.6',
      ],
      'sources': [
        'src/openvr.cpp'
      ],
      'include_dirs': [
        "<!(node -e \"require('nan')\")",
        './deps/openvr/headers',
      ],
      'conditions': [
        ['OS=="linux"', {
          'library_dirs': ['./deps/openvr/lib/linux64'],
          'libraries': ['libopenvr_api.so']
        }],
        ['OS=="mac"', {
          'library_dirs': ['./deps/openvr/lib/osx32'],
          'libraries': ['libopenvr_api.dylib']
        }],
        ['OS=="win"', {
          'library_dirs': ['./deps/openvr/lib/win64'],
          'libraries': ['openvr_api.lib']
          'defines' : ['WIN32_LEAN_AND_MEAN', 'VC_EXTRALEAN'],
          'msvs_settings' : {
            'VCCLCompilerTool' : {
              'AdditionalOptions' : ['/O2','/Oy','/GL','/GF','/Gm-','/EHsc','/MT','/GS','/Gy','/GR-','/Gd']
            },
            'VCLinkerTool' : {
              'AdditionalOptions' : ['/OPT:REF','/OPT:ICF','/LTCG']
            },
          },
        }],
      ],
    }
  ]
}
