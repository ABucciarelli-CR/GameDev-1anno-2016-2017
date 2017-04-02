using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerGranadeLaunch : MonoBehaviour 
{
	public int MaxGranade = 3;
	public float timeBetweenGranades = 2.0f;
	public GameObject Granade;

	void Update () 
	{
		
		if(Input.GetMouseButtonDown(1) && MaxGranade > 0)
		{
			MaxGranade -= 1;
			Instantiate (Granade, transform.position, transform.rotation);
		}
	}
}
