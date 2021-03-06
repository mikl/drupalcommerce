<?php
// $Id$

/**
 * @file
 */


/**
 * Menu callback: display an overview of available types.
 */
function commerce_product_ui_types_overview() {
  drupal_add_css(drupal_get_path('module', 'commerce_product_ui') . '/theme/commerce_product_ui.types.css');

  $header = array(
    t('Name'),
    t('Operations'),
  );

  $rows = array();

  // Loop through all defined product types.
  foreach (commerce_product_types() as $type => $product_type) {
    // Build the operation links for the current product type.
    $links = menu_contextual_links('commerce-product-type', 'admin/commerce/products/types', array(strtr($type, array('_' => '-'))));

    // Add the product type's row to the table's rows array.
    $rows[] = array(
      theme('product_type_admin_overview', array('product_type' => $product_type)),
      theme('links', array('links' => $links, 'attributes' => array('class' => 'links inline operations'))),
    );
  }

  // If no product types are defined...
  if (empty($rows)) {
    // Add a standard empty row with a link to add a new product type.
    $rows[] = array(
      array(
        'data' => t('There are no product types yet. <a href="@link">Add product type</a>.', array('@link' => url('admin/commerce/products/types/add'))),
        'colspan' => 2,
      )
    );
  }

  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Builds an overview of a product type for display to an administrator.
 *
 * @param $variables
 *   An array of variables used to generate the display; by default includes the
 *     type key with a value of the product type object.
 *
 * @ingroup themeable
 */
function theme_product_type_admin_overview($variables) {
  $product_type = $variables['product_type'];

  $output = check_plain($product_type->name);
  $output .= ' <small> (Machine name: ' . check_plain($product_type->type) . ')</small>';
  $output .= '<div class="description">' . filter_xss_admin($product_type->description) . '</div>';

  return $output;
}

/**
 * Form callback wrapper: create or edit a product type.
 *
 * @param $product_type
 *   The product type object being edited by this form.
 *
 * @see commerce_product_product_type_form()
 */
function commerce_product_ui_product_type_form_wrapper($product_type) {
  // Add the breadcrumb for the form's location.
  commerce_product_ui_set_breadcrumb(TRUE);

  // Include the forms file from the Product module.
  module_load_include('inc', 'commerce_product_ui', 'includes/commerce_product_ui.forms');

  return drupal_get_form('commerce_product_ui_product_type_form', $product_type);
}

/**
 * Form callback wrapper: confirmation form for deleting a product type.
 *
 * @param $product_type
 *   The product type object being deleted by this form.
 *
 * @see commerce_product_product_type_delete_form()
 */
function commerce_product_ui_product_type_delete_form_wrapper($product_type) {
  // Add the breadcrumb for the form's location.
  commerce_product_ui_set_breadcrumb(TRUE);

  // Don't allow deletion of product types that have products already.
  if (($count = db_query("SELECT product_id FROM {commerce_product} WHERE type = :product_type", array(':product_type' => $product_type->type))->rowCount()) > 0) {
    drupal_set_title(t('Cannot delete the %name product type', array('%name' => $product_type->name)), PASS_THROUGH);
    return t('There are @count products of this type. It cannot be deleted.', array('@count' => $count));
  }

  // Include the forms file from the Product module.
  module_load_include('inc', 'commerce_product_ui', 'includes/commerce_product_ui.forms');

  return drupal_get_form('commerce_product_ui_product_type_delete_form', $product_type);
}
