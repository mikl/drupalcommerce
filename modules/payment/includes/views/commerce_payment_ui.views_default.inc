<?php
// $Id$

/**
 * Views for the payment UI.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_payment_ui_views_default_views() {
  $views = array();

  // Payment transaction View with the totals area handler in the footer.
  $view = new view;
  $view->name = 'commerce_payment_order';
  $view->description = 'Display and total an order\'s payment transaction history.';
  $view->tag = 'commerce';
  $view->view_php = '';
  $view->base_table = 'commerce_payment_transaction';
  $view->is_cacheable = FALSE;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer payments';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'status' => 'status',
    'created' => 'created',
    'payment_method' => 'payment_method',
    'remote_id' => 'remote_id',
    'message' => 'message',
    'amount' => 'amount',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'status' => array(
      'sortable' => 0,
      'align' => 'views-align-center',
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'payment_method' => array(
      'sortable' => 1,
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'remote_id' => array(
      'sortable' => 0,
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'message' => array(
      'sortable' => 0,
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'amount' => array(
      'sortable' => 1,
      'align' => 'views-align-right',
      'separator' => '',
    ),
    'operations' => array(
      'align' => 'views-align-left',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Footer: Commerce Payment Transaction: Totals */
  $handler->display->display_options['footer']['totals']['id'] = 'totals';
  $handler->display->display_options['footer']['totals']['table'] = 'commerce_payment_transaction';
  $handler->display->display_options['footer']['totals']['field'] = 'totals';
  $handler->display->display_options['footer']['totals']['empty'] = TRUE;
  $handler->display->display_options['footer']['totals']['add_payment_form'] = 1;
  /* Relationship: Commerce Payment Transaction: Order ID */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'commerce_payment_transaction';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['required'] = 1;
  /* Field: Commerce Payment Transaction: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_payment_transaction';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  /* Field: Commerce Payment Transaction: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_payment_transaction';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/d/Y';
  /* Field: Commerce Payment Transaction: Payment method */
  $handler->display->display_options['fields']['payment_method']['id'] = 'payment_method';
  $handler->display->display_options['fields']['payment_method']['table'] = 'commerce_payment_transaction';
  $handler->display->display_options['fields']['payment_method']['field'] = 'payment_method';
  $handler->display->display_options['fields']['payment_method']['label'] = 'Method';
  $handler->display->display_options['fields']['payment_method']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['payment_method']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['payment_method']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['payment_method']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['payment_method']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['payment_method']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['payment_method']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['payment_method']['alter']['html'] = 0;
  $handler->display->display_options['fields']['payment_method']['hide_empty'] = 0;
  $handler->display->display_options['fields']['payment_method']['empty_zero'] = 0;
  /* Field: Commerce Payment Transaction: Remote ID */
  $handler->display->display_options['fields']['remote_id']['id'] = 'remote_id';
  $handler->display->display_options['fields']['remote_id']['table'] = 'commerce_payment_transaction';
  $handler->display->display_options['fields']['remote_id']['field'] = 'remote_id';
  $handler->display->display_options['fields']['remote_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['remote_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['remote_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['remote_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['remote_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['remote_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['remote_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['remote_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['remote_id']['empty'] = '-';
  $handler->display->display_options['fields']['remote_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['remote_id']['empty_zero'] = 0;
  /* Field: Commerce Payment Transaction: Message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'commerce_payment_transaction';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['label'] = 'Result message';
  $handler->display->display_options['fields']['message']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['message']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['message']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['message']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['message']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['message']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['message']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['message']['alter']['html'] = 0;
  $handler->display->display_options['fields']['message']['empty'] = '-';
  $handler->display->display_options['fields']['message']['hide_empty'] = 0;
  $handler->display->display_options['fields']['message']['empty_zero'] = 0;
  /* Field: Commerce Payment Transaction: Amount */
  $handler->display->display_options['fields']['amount']['id'] = 'amount';
  $handler->display->display_options['fields']['amount']['table'] = 'commerce_payment_transaction';
  $handler->display->display_options['fields']['amount']['field'] = 'amount';
  $handler->display->display_options['fields']['amount']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['amount']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['amount']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['amount']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['amount']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['amount']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['amount']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['amount']['alter']['html'] = 0;
  $handler->display->display_options['fields']['amount']['hide_empty'] = 0;
  $handler->display->display_options['fields']['amount']['empty_zero'] = 0;
  /* Field: Commerce Payment Transaction: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'commerce_payment_transaction';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['label'] = 'Operations';
  $handler->display->display_options['fields']['operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['operations']['empty_zero'] = 0;
  /* Argument: Commerce Order: Order ID */
  $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['relationship'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['order_id']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['order_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['order_id']['not'] = 0;

  $views[$view->name] = $view;

  return $views;
}
