#!/bin/bash
# Simple script to install drupal for travis-ci running.
#
## Template modified from http://drupal.org/project/panopoly

set -e $DRUPAL_TI_DEBUG

# Ensure the right Drupal version is installed and upgraded.
# Note: This runs our custom version of drupal_ti_install_drupal in
#       .drupal-ti/functions/wetkit.sh.
drupal_ti_ensure_drupal

# Our tests depend on panopoly_test.
drush en -y wetkit_test

# Clear caches and run a web server.
drupal_ti_clear_caches
drupal_ti_run_server

# Start xvfb and selenium.
drupal_ti_ensure_xvfb
drupal_ti_ensure_webdriver

# Force chromedriver to v2.28
cd $DRUPAL_TI_BIN_DIR
rm chromedriver
wget http://chromedriver.storage.googleapis.com/2.28/chromedriver_linux64.zip
unzip chromedriver_linux64.zip
rm -f chromedriver_linux64.zip
chmod a+x chromedriver
