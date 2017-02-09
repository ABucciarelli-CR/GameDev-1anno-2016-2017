using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class CameraController : MonoBehaviour 
{
	public Transform playerTransform;
	private Vector3 _offset;

	// Use this for initialization
	void Start () 
	{
		_offset = transform.position - playerTransform.position;
	}
	
	// Update is called once per frame
	void Update () 
	{
		transform.position = playerTransform.position + _offset;
	}
}
