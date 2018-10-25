/*
 * (C) Copyright 2016 Kurento (http://kurento.org/)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */


module.exports = function(grunt)
{
  var DIST_DIR = 'dist';

  var pkg = grunt.file.readJSON('package.json');

  const PKG_BROWSER = 'lib/browser.js';

  // Project configuration.
  grunt.initConfig({
    pkg: pkg,

    // Plugins configuration
    clean:
    {
      'doc':     '<%= jsdoc.all.dest %>',
      'browser': DIST_DIR
    },

    // Generate documentation
    jsdoc:
    {
      all:
      {
        src: [
          'README.md',
          'lib/**/*.js',
          'test/*.js'
        ],
        dest: 'doc/jsdoc'
      }
    },

    // Generate browser versions and mapping debug file
    browserify:
    {
      options: {
        alias:    ['.:<%= pkg.name %>'],
        external: [
          'es6-promise',
          'inherits',
          'kurento-client',
          'promisecallback'
        ]
      },

      'standard':
      {
        src:  PKG_BROWSER,
        dest: DIST_DIR+'/<%= pkg.name %>.js'
      },

      'minified':
      {
        src:  PKG_BROWSER,
        dest: DIST_DIR+'/<%= pkg.name %>.min.js',

        options:
        {
          browserifyOptions: {
            debug: true
          },
          plugin: [
            ['minifyify',
             {
               compressPath: DIST_DIR,
               map:          '<%= pkg.name %>.map',
               output:       DIST_DIR+'/<%= pkg.name %>.map'
             }]
          ]
        }
      }
    },

    // Generate bower.json file from package.json data
    sync:
    {
      bower:
      {
        options:
        {
          sync: [
            'name', 'description', 'license', 'keywords', 'homepage',
            'repository'
          ],
          overrides: {
            authors: (pkg.author ? [pkg.author] : []).concat(pkg.contributors || []),
            ignore: ['doc/', 'lib/', 'Gruntfile.js', 'package.json'],
            main: DIST_DIR+'/<%= pkg.name %>.js'
          }
        }
      }
    }  });

  // Load plugins
  grunt.loadNpmTasks('grunt-browserify');
  grunt.loadNpmTasks('grunt-contrib-clean');
  grunt.loadNpmTasks('grunt-jsdoc');
  grunt.loadNpmTasks('grunt-npm2bower-sync');

  // Alias tasks
  grunt.registerTask('default', ['clean', 'jsdoc', 'browserify', 'sync:bower']);
};
